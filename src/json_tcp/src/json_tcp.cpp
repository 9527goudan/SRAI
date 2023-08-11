#include"jsoncpp/json/json.h"
#include"ros/ros.h"
#include"fstream"

int main(int argc, char *argv[])
{
  ros::init(argc,argv,"jsonParam");
  ros::NodeHandle np;

  std::ofstream jsonFile;
  jsonFile.open("/home/goudan/srbot_ws-C/src/speech_recognizer_ifly/param/BeginParam.json",std::ios::out | std::ios::trunc);

  if(jsonFile.is_open())
  {
    Json::Value root;
    root["GM0"]="sample_rate";
    root["GM1"]="result_type";
    root["GM2"]="result_encoding";

    root["CLOUD0"]="sub";
    root["CLOUD1"]="language";
    root["CLOUD2"]="domain";
    root["CLOUD3"]="accent";

    ROS_INFO("0000000");
    jsonFile<<root;
    ROS_INFO("1111111");
  }
  else
    printf("jsonFile.json 打开失败！！\n");
  jsonFile.close();
  return 0;
}
