#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "linuxrec.h"
#include "msp_cmn.h"
#include "msp_errors.h"
#include "ros/ros.h"
#include"std_msgs/String.h"
//#include "msges/mic.h"

static ros::Publisher PubAudio;
static std_msgs::String MyAudioData;
//static msges::mic MicData;

void OnDataIndCB(char *Data,unsigned long Datalen,void *UserPara)
{
  std::string DataToUint8_t = Data;
  if(nullptr == Data || 0 == Datalen)
    return;
  /*
   * for (uint64_t i_ = 0;i_<DataToUint8_t.size();i_++)
  {
    //MicData.data[i_] = std::stoul(DataToUint8_t.c_str(),i_,0) ;
    std::cout<<MicData<<std::endl;
  }
*/
  MyAudioData.data = Data;
  PubAudio.publish(MyAudioData);
  Data = nullptr;
}

int main(int argc, char *argv[])
{
  ros::init(argc,argv,"PubAudioNode");
  ros::NodeHandle audioNp;
  PubAudio = audioNp.advertise<std_msgs::String>("/Audio",50);
  //PubAudio = audioNp.advertise<msges::mic>("/Audio",50);

  int ret = get_input_dev_num();
  if(0 == ret)
    printf("无可用录音设备\n");
  else
    printf("ret=%d\n",ret);

  struct recorder *outRec;//指向录音对象
  ret = create_recorder(&outRec,OnDataIndCB,nullptr);
  if(MSP_SUCCESS != ret)
  {
    printf("录音对象创建失败 ret=%d\n",ret);
    return -1;
  }
  record_dev_id recID = get_default_input_dev();
  printf("默认录音设备 ID=%d\n",recID.u.index);
  WAVEFORMATEX fmt;
  fmt.wFormatTag        = WAVE_FORMAT_PCM;
  fmt.nChannels         = 1;
  fmt.nSamplesPerSec    = 16000;
  fmt.nAvgBytesPerSec   = 32000;
  fmt.nBlockAlign       = 2;
  fmt.wBitsPerSample    = 16;
  fmt.cbSize            = sizeof (WAVEFORMATEX);

  ret = open_recorder(outRec,recID,&fmt);
  if(0 != ret)
  {
    printf("录音设备打开失败 ret=%d\n",ret);
    goto goto1;
  }
  ret = start_record(outRec);
  if(0 != ret)
  {
    printf("录音失败 ret=%d\n",ret);
    goto goto2;
  }
  while (ros::ok())
  {
    ret = stop_record(outRec);
    if(0 == ret)
      printf("暂停录音\n");
    else
      printf("stop_record()出错  ret=%d",ret);
    ros::spinOnce();
    sleep(5);
    if(is_record_stopped(outRec))
    {
      ret = start_record(outRec);
      if(0 == ret)
        printf("开启录音\n");
      else
      {
        printf("start_record()出错  ret=%d\n",ret);
        break;
      }
    }
  }
  printf("关闭录音设备中...\n");
  while (!is_record_stopped(outRec))
  {
    stop_record(outRec);//停止录音
    usleep(200*1000);
  }
goto2:
  close_recorder(outRec);//关闭录音设备
goto1:
  destroy_recorder(outRec);//销毁录音对象
  return 0;
}
