/*
* 语音听写(iFly Auto Transform)技术能够实时地将语音转换成对应的文字。
*/
#include"ros/ros.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "qisr.h"
#include "msp_cmn.h"
#include "msp_errors.h"
#include "speech_recognizer.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"

#define FRAME_LEN	640
#define	BUFFER_SIZE	4096
#define SpeechRecognitionTime (8.0)

static ros::Publisher VoiceToText_pub;
static const char* session_begin_params;
static bool Upwaken = false;
static void show_result(char *string, char is_over)
{
  if(Upwaken)
  {
    std_msgs::String VoiceText;
    VoiceText.data = string;
    printf("\r识别结果: [ %s ]", VoiceText.data.c_str());
    if(is_over)
      putchar('\n');
    VoiceToText_pub.publish(VoiceText);
    Upwaken = false;
  }
}

static char *g_result = nullptr;
static unsigned int g_buffersize = BUFFER_SIZE;

void on_result(const char *result, char is_last)
{
  if (result) {
    size_t left = g_buffersize - 1 - strlen(g_result);
    size_t size = strlen(result);
    if (left < size) {
      g_result = (char*)realloc(g_result, g_buffersize + BUFFER_SIZE);
      if (g_result)
        g_buffersize += BUFFER_SIZE;
      else {
        printf("mem alloc failed\n");
        return;
      }
    }
    strncat(g_result, result, size);
    show_result(g_result, is_last);
  }
}
void on_speech_begin()
{
  if (g_result)
  {
    free(g_result);
  }
  g_result = (char*)malloc(BUFFER_SIZE);
  g_buffersize = BUFFER_SIZE;
  memset(g_result, 0, g_buffersize);

  printf("Start Listening...\n");
}
void on_speech_end(int reason)
{
  if (reason == END_REASON_VAD_DETECT)
    printf("\nSpeaking done \n");
  else
    printf("\nRecognizer error %d\n", reason);
}

/* 麦克风读取音频数据 */
static void demo_mic(const char* session_begin_params)
{
  int errcode;
  int i = 0;

  struct speech_rec iat;

  struct speech_rec_notifier recnotifier = {
    on_result,
    on_speech_begin,
    on_speech_end
  };

  errcode = sr_init(&iat, session_begin_params, SR_MIC, &recnotifier);
  if (errcode) {
    printf("speech recognizer init failed\n");
    return;
  }
  errcode = sr_start_listening(&iat);
  if (errcode) {
    printf("start listen failed %d\n", errcode);
  }
  double time0,timeNow;
  time0 = ros::Time::now().toSec();
  while(1)
  {
    timeNow = ros::Time::now().toSec();
    if ((timeNow-time0) > SpeechRecognitionTime || iat.ep_stat == MSP_EP_TIMEOUT)//超时或音频已写入完
    {
      printf("音频写入完成\n");
      break;
    }
    usleep(80*1000);
  }
  errcode = sr_stop_listening(&iat);
  if (errcode) {
    printf("stop listening failed %d\n", errcode);
  }
  sr_uninit(&iat);
}

void WakenUpSubCB(const std_msgs::Bool WakenUp)
{
  if(WakenUp.data)
  {
    usleep(1400*1000);//等待唤醒提示音播放完
    Upwaken = true;
    demo_mic(session_begin_params);
  }
}

/* main thread: start/stop record ; query the result of recgonization.
 * record thread: record callback(data write)
 * helper thread: ui(keystroke detection)
 */
int main(int argc, char* argv[])
{
  ros::init(argc,argv,"VoiceIat");
  ros::NodeHandle IatNp;
  VoiceToText_pub = IatNp.advertise<std_msgs::String>("/VoiceCommand",100);
  ros::Subscriber WakenUp_sub = IatNp.subscribe("/WakenUp",100,&WakenUpSubCB);

  int ret = MSP_SUCCESS;
  /* login params, please do keep the appid correct */
  const char* login_params = "appid = 6597fc2f, work_dir = .";
  /*
  * See "iFlytek MSC Reference Manual"
  */
  session_begin_params =
    "sub = iat, domain = iat, language = zh_cn, "
    "accent = mandarin, sample_rate = 16000, "
    "result_type = plain, result_encoding = utf8";

  /* Login first. the 1st arg is username, the 2nd arg is password
   * just set them as NULL. the 3rd arg is login paramertes
   * */
  ret = MSPLogin(nullptr, nullptr, login_params);
  if (MSP_SUCCESS != ret)	{
    printf("MSPLogin failed , Error code %d.\n",ret);
    goto exit; // login fail, exit the program
  }
  ROS_INFO("Voice dictation started successfully ---iatVoiceNode");
  ros::spin();
exit:
  MSPLogout(); // Logout...

  return 0;
}
