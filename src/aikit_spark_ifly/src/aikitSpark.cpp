#include<ros/ros.h>
//#include<jsoncpp/json/json.h>
#include<std_msgs/String.h>
#include<aikit_spark_api.h>

using namespace std;
using namespace AIKIT;

struct UsrCtx {
    string chatID;
};

static ros::Publisher PubSparkResult;

void IatTextCB(const std_msgs::String &VoiceText)
{
  string UserID;
  ros::param::get("/AiKitSparkNode/UserID",UserID="18123233228");
  //请求参数配置
  ChatParam* config = ChatParam::builder();
  config->uid(UserID.c_str())
        ->domain("general")
        ->auditing("default")
        ->maxToken(4096);

  // 设置chatID,使用static变量,防止回调时被销毁。
  // 用于用户动态控制会话轮次
  static UsrCtx usr = {"FistRound"};

  int ret = AIKIT_AsyncChat(config, VoiceText.data.c_str(), &usr);
  if(ret != 0)
    ROS_ERROR("AIKIT_AsyncChat() ERROR!!    ret=%d",ret);
}

static std_msgs::String SparkText;

//事件结束回调
static void chatOnToken(AIChat_Handle* handle, const int& completionTokens, const int& promptTokens, const int& totalTokens)
{
    if(handle!=nullptr){
        cout<<"chatID:"<<((UsrCtx*)handle->usrContext)->chatID<<", ";
    }
    cout<<"completionTokens:"<<completionTokens<<" promptTokens:"<<promptTokens<<" totalTokens:"<<totalTokens<<endl;
    PubSparkResult.publish(SparkText);
    cout<<"SparkText: [ "<<SparkText.data.c_str()<<" ]"<<endl;
    SparkText.data.clear();
}

void ConstCharToString(const char *string)
{
  char * _string = new char[strlen(string) + 1];
  strcpy(_string,string);
  SparkText.data += _string;
  delete [] _string;
}


//AI结果回调
static void chatOnOutput(AIChat_Handle* handle, const char* role, const char* content, const int& index)
{
    if(handle!=nullptr){
        cout<<"chatID:"<<((UsrCtx*)handle->usrContext)->chatID<<", index"<<index<<", ";
    }
    cout<<"role:"<<role<<", content: "<<content<<endl;
    if(0 == strcmp(role,"assistant"))
      ConstCharToString(content);
}

//事件错误回调
static void chatOnError(AIChat_Handle* handle, const int& err, const char* errDesc)
{
    if(handle!=nullptr){
        cout<<"chatID:"<<((UsrCtx*)handle->usrContext)->chatID<<", ";
    }
    printf("chatOnError: err:%d,desc:%s\n",err,errDesc);
}


int AIKIT_INIT_SDK()
{
  AIKIT_SetLogInfo(100,0,nullptr);

  string appID,apiKey,apiSecret;
  ros::param::get("/AiKitSparkNode/appID",appID = "68dc26a6");
  ros::param::get("/AiKitSparkNode/apiKey",apiKey = "ad4b86c7eb1ee0493f5efa1174b9dcc4");
  ros::param::get("/AiKitSparkNode/apiSecret",apiSecret = "ZmYwZTRhYzYxMTA4MDJkZTFlZDY1NDZk");

  AIKIT_InitParam initParam{};
  initParam.appID = appID.c_str();
  initParam.apiKey = apiKey.c_str();
  initParam.apiSecret = apiSecret.c_str();

  int ret = AIKIT_Init(&initParam);
  if(0 != ret)
  {
    ROS_ERROR("AIKIT_Init() ERROR!!  ret=%d",ret);
    return ret;
  }
  AIKIT_ChatCallback({ chatOnOutput, chatOnToken, chatOnError });
  SparkText.data.clear();
  return ret;
}


int main(int argc, char *argv[])
{
  ros::init(argc,argv,"AiKitSpark_1_NODE");
  ros::NodeHandle SparkNH;
  ros::Subscriber SubVoiceText = SparkNH.subscribe("/VoiceCommand",100,&IatTextCB);//订阅语音识别结果
  PubSparkResult = SparkNH.advertise<std_msgs::String>("/TextToVoice",100);
  ros::Rate rate(5);
  if(0 != AIKIT_INIT_SDK())
    goto ESC;

  while (ros::ok())
  {
    rate.sleep();
    ros::spinOnce();
  }
ESC:
  AIKIT_UnInit();
  return 0;
}
