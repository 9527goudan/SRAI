#include"ros/ros.h"
#include"std_msgs/String.h"
#include"std_msgs/Bool.h"
#include "qisr.h"
#include "msp_cmn.h"
#include "msp_errors.h"
#include "std_msgs/String.h"
#include "std_msgs/Bool.h"
#include"string"
#include"linuxrec.h"
#include"jsoncpp/json/json.h"
#include"fstream"
#include"string.h"

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

class QISR
{
public:
  QISR();
  ~QISR();
  int MSP_INIT();//初始化MSP
  int MIC_INIT();//麦克风初始化
  void SpeechToText();//开始语音转文字
  void WakenUP_CB(const std_msgs::Bool &waken_up);//订阅“唤醒”回调
private:
  ros::NodeHandle NH;
  ros::Subscriber WakenUP_sub;
  ros::Publisher  Txt_pub;
  //ros::ServiceServer wakenUpServer;

  const char* QISRsessionID;

  struct recorder *outRec;//指向录音对象
  record_dev_id recID;
  WAVEFORMATEX _fmt;
  double RecTime;
};

static bool UP_waken;
void QISR::WakenUP_CB(const std_msgs::Bool &waken_up)
{
  UP_waken = waken_up.data;
}

//构造
QISR::QISR()
{
  Txt_pub = NH.advertise<std_msgs::String>("/VoiceCommand",100);
  WakenUP_sub = NH.subscribe("/WakenUp",100,&QISR::WakenUP_CB,this);
  //wakenUpServer = NH.advertiseService("",,100);
  _fmt = DEFAULT_FORMAT;
  ros::param::get("/QISR_Node/GM_RecTime",RecTime=8.0);
}

//初始化MSP
int QISR::MSP_INIT()
{
  std::string Login_params;
  ros::param::get("/QISR_Node/GM_appid",Login_params = "68dc26a6");
  Login_params = "appid=" + Login_params + ", work_dir = .";
  int rec = MSPLogin(nullptr,nullptr,Login_params.c_str());
  if(MSP_SUCCESS != rec)
    ROS_ERROR("MSPLogin() param error  rec=%d",rec);
  return rec;
}

static bool QISR_ERR = false;//错误调用标志
static std::string IdentificationResult;

std::string ConstCharToString(const char* string)
{
  char * _string = new char[std::strlen(string)+1];
  std::strncpy(_string,string,std::strlen(string));
  IdentificationResult += _string;
  delete [] _string;
  return IdentificationResult;
}

//音频数据回调
void MIC_DataCB(char *MIC_Data,unsigned long MIC_Datalen,void *QIS_SsionID)
{
  const char *ssionID = (const char *)(QIS_SsionID);
  int ret = 1027;
  int EpStatus = 1027;
  int RsltStatus = 1027;
  static int AudioStatus = MSP_AUDIO_SAMPLE_FIRST;
  if(UP_waken)
  {
    //写入音频
    ret = QISRAudioWrite(ssionID,(const void*)MIC_Data,(unsigned int)MIC_Datalen,AudioStatus,&EpStatus,&RsltStatus);
    if(MSP_SUCCESS != ret)
    {
      ROS_ERROR("QISRAudioWrite() ERROR!  ret=%d",ret);
      QISR_ERR = true;
      AudioStatus = MSP_AUDIO_SAMPLE_FIRST;
      return;
    }
    AudioStatus = MSP_AUDIO_SAMPLE_CONTINUE;
    if(MSP_EP_AFTER_SPEECH == EpStatus)
    {
      UP_waken = false;
      ret = QISRAudioWrite(ssionID,nullptr,0,MSP_AUDIO_SAMPLE_LAST,&EpStatus,&RsltStatus);
      //ROS_INFO("444444444444444");
      //QISR_ERR = true;
    }
  }
  if(MSP_REC_STATUS_SUCCESS == RsltStatus)
  {
    //ROS_INFO("11111111111111");
    const char* Rslut_string = QISRGetResult(ssionID,&RsltStatus,0,&ret);
    //ROS_INFO("33333333333333");
    if(MSP_SUCCESS != ret)
    {
      ROS_ERROR("QISRGetResult() ERROR ! ret=%d",ret);
      QISR_ERR = true;
      RsltStatus = MSP_REC_STATUS_COMPLETE;
    }
    if(nullptr != Rslut_string)
    {
      //ROS_INFO("2222222222222222");
      ConstCharToString(Rslut_string);
      //std::cout<<"IdentificationResult : ["<<IdentificationResult.c_str()<<" ]"<<std::endl;
    }
  }
  else if(MSP_REC_STATUS_INCOMPLETE != RsltStatus)
  {
    QISR_ERR = true;
    AudioStatus = MSP_AUDIO_SAMPLE_FIRST;
  }
}

//麦克风初始化
//返回值：0 录音设备打开成功  1 无录音设备  -1 录音对象创建失败  其他值 录音设备打开失败
int QISR::MIC_INIT()
{
  int ret = get_input_dev_num();
  if(0 == ret)
  {
    printf("无可用录音设备\n");
    return 1;
  }
  ret = create_recorder(&outRec,MIC_DataCB,(void*)QISRsessionID);
  if(MSP_SUCCESS != ret)
  {
    printf("录音对象创建失败 ret=%d\n",ret);
    return -1;
  }
  recID = get_default_input_dev();
  ret = open_recorder(outRec,recID,&_fmt);
  if(0 != ret)
    printf("录音设备打开失败 ret=%d\n",ret);
  return ret;
}

std::string GetParams()
{
  Json::Value root;
  std::ifstream jsonFile;
  std::string BeginParams,Params;
  ros::param::get("/QISR_Node/GM_JsonPath",Params);
  jsonFile.open(Params,std::ios::in);
  if(jsonFile.is_open())
  {
    Params.clear();
    jsonFile>>root;
    for (int i=0;i<=2;i++)
    {
      ros::param::get("/QISR_Node/GM"+std::to_string(i),Params);
      BeginParams += root["GM" + std::to_string(i)].asString() + "=" + Params +",";
    }
    Params.clear();
    for (int j=0;j<=3;j++)
    {
      if(3 == j)
      {
        ros::param::get("/QISR_Node/CLOUD"+std::to_string(j),Params);
        BeginParams += root["CLOUD" + std::to_string(j)].asString() + "=" + Params;
      }
      else
      {
        ros::param::get("/QISR_Node/CLOUD"+std::to_string(j),Params);
        BeginParams += root["CLOUD" + std::to_string(j)].asString() + "=" + Params + ",";
      }
    }
  }
  return BeginParams;
}

//语音转文字
void QISR::SpeechToText()
{
  int errCode = MSP_SUCCESS;
  std::string QISR_BeginParams = GetParams();
  //开启一次语音识别
  QISRsessionID = QISRSessionBegin(nullptr,QISR_BeginParams.c_str(),&errCode);
  if(MSP_SUCCESS != errCode)
  {
    ROS_ERROR("QISRSessionBegin() Error!!  ret=%d",errCode);
    return;
  }
  //初始化麦克风
  int ret = MIC_INIT();
  if(0 != ret)
  {
    QISRSessionEnd(QISRsessionID,"MIC_INIT ERROR");
    if(1 != ret || -1 != ret)
      destroy_recorder(outRec);
    return;
  }
  //开始录音
  ret = start_record(outRec);
  if(0 != ret)
  {
    ROS_ERROR("MIC start_record() ERROR!  ret=%d",ret);
    close_recorder(outRec);
    destroy_recorder(outRec);
    QISRSessionEnd(QISRsessionID,"MIC start_record() ERROR!");
    return;
  }
  IdentificationResult.clear();
  printf("开始识别....\n");
  double timeOld,timeNow;
  timeOld = timeNow = ros::Time::now().toSec();
  ros::Rate _rate(20);
  while (!QISR_ERR || RecTime < (timeNow - timeOld))
  {
    //写入音频数据或超时退出
    timeNow = ros::Time::now().toSec();
    _rate.sleep();
    ros::spinOnce();
    usleep(80*1000);
  }
  while (!is_record_stopped(outRec))
  {
    stop_record(outRec);
    usleep(200*1000);
    if(!ros::ok())
      break;
  }
  QISR_ERR = false;
  //等待获取识别结果
  std_msgs::String VoiceText;
  VoiceText.data = IdentificationResult;
  std::cout<<"reslut: [ "<<IdentificationResult.c_str()<<" ]"<<std::endl;
  printf("结束识别....\n");
  Txt_pub.publish(VoiceText);
  IdentificationResult.clear();
  close_recorder(outRec);
  destroy_recorder(outRec);
  QISRSessionEnd(QISRsessionID,"识别结束");
}

//析构
QISR::~QISR()
{
  MSPLogout();
}

int main(int argc, char *argv[])
{
  ros::init(argc,argv,"QISR_iFLY");
  QISR qisr;
  if(MSP_SUCCESS == qisr.MSP_INIT())
  {
    ros::Rate Speen(10);
    while (ros::ok())
    {
      if(UP_waken)
      {
        qisr.SpeechToText();
        UP_waken = false;
      }
      Speen.sleep();
      ros::spinOnce();
    }
  }
  ros::spin();
  return 0;
}
