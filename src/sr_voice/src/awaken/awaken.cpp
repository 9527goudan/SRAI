#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "msp_cmn.h"
#include "qivw.h"
#include "msp_errors.h"
#include "ros/ros.h"
#include "std_msgs/Bool.h"
#include "std_msgs/String.h"
#include "linuxrec.h"
//#include"audio_common_msgs/AudioData.h"

#define DEFAULT_FORMAT		\
{\
  WAVE_FORMAT_PCM,	\
  1,			\
  16000,			\
  32000,			\
  2,			\
  16,			\
  sizeof(WAVEFORMATEX)	\
}

static int StatusAudio = MSP_AUDIO_SAMPLE_FIRST;

class AWAKENUP
{
public:
  AWAKENUP();//语音唤醒参数获取，创建“awakenup”唤醒话题
  ~AWAKENUP();
  int MSP_InIt();
  void GetVersion();
  int MIC_InIt();
  void WakeUpResult(bool result,std::string response,uint DormancyDuration);
  struct recorder *outRec;//指向录音对象
private:
  ros::NodeHandle awakenUpNH;
  ros::Publisher awakeUpPub;
  ros::Publisher awakeUpAudio;
  std_msgs::Bool WakenUpMsg;
  std_msgs::String WakenUpAudio;
  std::string MSPLoginParam,MSPSetParam_,ParamIvwBengin,engine_start,ivw_res_path,ivw_threshold,sst;
  const char* sessionID = nullptr;
  //MIC
  record_dev_id recID;
  WAVEFORMATEX fmt;
};

AWAKENUP::AWAKENUP()
{
  awakeUpPub = awakenUpNH.advertise<std_msgs::Bool>("/awakenup",50);
  awakeUpAudio = awakenUpNH.advertise<std_msgs::String>("/TextToVoice",100);
  ros::param::get("/awakenNode/MSPLoginParam",MSPLoginParam = "appid = 68dc26a6,work_dir = .");
  ros::param::get("/awakenNode/engine_start",engine_start = "ivw");
  ros::param::get("/awakenNode/ivw_res_path",ivw_res_path = "fo|/home/goudan/srbot_ws-C/src/sr_voice/bin/msc/res/ivw/wakeupresource.jet");
  ros::param::get("/awakenNode/ivw_threshold",ivw_threshold = "0:1450;1:1450;2:1450");
  ros::param::get("/awakenNode/sst",sst = "wakeup");

  MSPSetParam_ = "engine_start=" + engine_start + ",ivw_res_path=" + ivw_res_path;
  ParamIvwBengin = "ivw_threshold=" + ivw_threshold + ",sst=" + sst + ",ivw_res_path=" + ivw_res_path;

  fmt = DEFAULT_FORMAT;
  //fmt.nSamplesPerSec = 16000;
  //fmt.nAvgBytesPerSec = fmt.nBlockAlign * fmt.nSamplesPerSec;
  WakenUpMsg.data = false;
  WakenUpAudio.data.clear();
  awakeUpPub.publish(WakenUpMsg);
}
AWAKENUP::~AWAKENUP()
{
  if(0 != get_input_dev_num())
  {
    printf("关闭录音设备中...\n");
    while (!is_record_stopped(outRec))
    {
      stop_record(outRec);//停止录音
      usleep(200*1000);
    }

    close_recorder(outRec);//关闭录音设备
    destroy_recorder(outRec);//销毁录音对象
  }
  QIVWSessionEnd(sessionID,"ros::ok()");//结束语音唤醒
  MSPLogout();//MSP退出登陆
}

static bool AwakenUpTrueOrFalse = false;

//唤醒回调
int IvwCB(const char* sessionid,int msg,int param1,int param2,const void* info,void *userData)
{
  switch (msg)
  {
  case MSP_IVW_MSG_WAKEUP:   printf("唤醒消息\n info：[ %s ]  len:%d\n",info,param2);
                             AwakenUpTrueOrFalse = true;
                             break;// 唤醒消息，在info中给出唤醒结果缓存首地址，param2 给出唤醒结果的长度
  case MSP_IVW_MSG_ERROR :   printf("唤醒失败！\n ret:%d  \n",param1);
                             AwakenUpTrueOrFalse = false;
                             break;//出错通知消息，在param1 中给出错误码
  }
  return 0;
}

int AWAKENUP::MSP_InIt()
{
  //登陆MSPLonin
  int ret = MSPLogin(nullptr,nullptr,MSPLoginParam.c_str());
  if(MSP_SUCCESS == ret)
  {
    //离线引擎初始化
    ret = MSPSetParam("engine_start",MSPSetParam_.c_str());
    if(MSP_SUCCESS == ret)
    {
      //开始语音唤醒
      sessionID = QIVWSessionBegin(nullptr,ParamIvwBengin.c_str(),&ret);
      if(MSP_SUCCESS == ret)
      {
        //注册唤醒回调
        ret = QIVWRegisterNotify(sessionID,IvwCB,nullptr);
        if(MSP_SUCCESS != ret)
          printf("QIVWRegisterNotify()失败 ：%d\n",ret);
      }
      else
        printf("QIVWSessionBegin()失败 ：%d\n",ret);
    }
    else
      printf("离线引擎初始化失败 MSPSetParam():%d\n",ret);
  }
  else
    printf("MSPLongin()用户登陆失败 ：%d\n",ret);

  return ret;
}

void AWAKENUP::GetVersion()
{
  int ret = 0;
  //查询MSC版本号，离线唤醒版本号
  const char* msc_ivw = MSPGetVersion("ver_msc",&ret);
  if(MSP_SUCCESS == ret)
    printf("MSC版本号: %s\n",msc_ivw);
  const char* msc_ivw2 = MSPGetVersion("ver_ivw",&ret);
  if(MSP_SUCCESS == ret)
    printf("IVW版本号: %s\n",msc_ivw2);
}


static double time_0 = 0.0;
//音频数据回调
void OnDataIndCB(char *Data,unsigned long Datalen,void *UserPara)
{
  const char * session_ID = (const char *)UserPara;
  if(nullptr == Data || 0 == Datalen)
    return;

  double time_Now = ros::Time::now().toSec();
  if(5.0 < (time_Now - time_0))
  {
    StatusAudio = MSP_AUDIO_SAMPLE_LAST;
    time_0 = ros::Time::now().toSec();
  }
  if(!AwakenUpTrueOrFalse)
  {
    int ret = QIVWAudioWrite(session_ID,(const void*)Data,Datalen,StatusAudio);
    if(MSP_SUCCESS != ret)
    {
      StatusAudio = MSP_AUDIO_SAMPLE_LAST;
      printf("音频写入失败QIVWAudioWrite() error:%d\n ",ret);
    }
    StatusAudio = MSP_AUDIO_SAMPLE_CONTINUE;
  }
  else
  {
    StatusAudio = MSP_AUDIO_SAMPLE_LAST;
    int ret = QIVWAudioWrite(session_ID,nullptr,0,StatusAudio);
    if(MSP_SUCCESS != ret)
    {
      StatusAudio = MSP_AUDIO_SAMPLE_LAST;
      printf("音频写入失败QIVWAudioWrite() error:%d\n ",ret);
    }
  }
  usleep(200*1000);
}

/*返回值  0：无可用录音设备
 *      -1:录音对象创建失败
 *   其他值：录音设备号
*/
int AWAKENUP::MIC_InIt()
{
  int ret = get_input_dev_num();
  if(0 == ret)
  {
    printf("无可用录音设备\n");
    return ret;
  }
  ret = create_recorder(&outRec,OnDataIndCB,(void*)sessionID);
  if(MSP_SUCCESS != ret)
  {
    printf("录音对象创建失败 ret=%d\n",ret);
    return -1;
  }
  recID = get_default_input_dev();
  ret = open_recorder(outRec,recID,&fmt);
  if(0 != ret)
    printf("录音设备打开失败 ret=%d\n",ret);
  ret = start_record(outRec);
  if(0 != ret)
    printf("录音失败 ret1=%d\n",ret);
  return ret;
}

void AWAKENUP::WakeUpResult(bool result,std::string response,uint DormancyDuration = 1)
{
  WakenUpMsg.data = result;
  WakenUpAudio.data = response;
  awakeUpAudio.publish(WakenUpAudio);
  awakeUpPub.publish(WakenUpMsg);
  sleep(DormancyDuration);
}

int main(int argc, char *argv[])
{
  ros::init(argc,argv,"WakenUpNode");
  AWAKENUP AwakenUp;
  AwakenUp.MSP_InIt();
  AwakenUp.GetVersion();
  time_0 = ros::Time::now().toSec();
  AwakenUp.MIC_InIt();

  while (ros::ok())
  {
    if(AwakenUpTrueOrFalse)
    {
      StatusAudio = MSP_AUDIO_SAMPLE_FIRST;
      AwakenUp.WakeUpResult(true,"主人我在，请尽情吩咐小笨",4);
      AwakenUpTrueOrFalse = false;
    }
    usleep(80*1000);
    ros::spinOnce();
  }

  return 0;
}

