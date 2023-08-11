#include<ros/ros.h>
#include<boost/uuid/uuid.hpp>
#include<boost/uuid/uuid_io.hpp>
#include<boost/uuid/uuid_generators.hpp>
#include<string>
#include<iostream>
#include"fstream"
#include"std_msgs/String.h"
#include"jsoncpp/json/json.h"
#include"ctime"

int main(int argc, char *argv[])
{
  ros::init(argc,argv,"robotIdUuid");
  ros::NodeHandle np_uuid;
  ros::Publisher pubRobotID=np_uuid.advertise<std_msgs::String>("robotID",100);
  std_msgs::String robotID;
  std::string pathFile;//文件路径
  pathFile.clear();
  np_uuid.getParam("/uuid_node/pathFile",pathFile="/home/srai/srbot_ws-C/src/robot_id-uuid/param/robotid.txt");

  std::fstream RobotIDFile;
  //先读文件判断文件是否存在，存在：读出id发布。
  RobotIDFile.open(pathFile,std::ios::in);
  if(RobotIDFile.is_open())
  {
    char endMark;
    RobotIDFile>>endMark;
    if(RobotIDFile.eof() || endMark==' ')
    {
      printf("文件为空\n");
      goto ID_Generation;
    }
    else
    {
      RobotIDFile.clear();
      RobotIDFile.seekg(0,std::ios::beg);
      printf("%s 文件存在且不为空\n",pathFile.c_str());
      robotID.data.clear();
      RobotIDFile>>robotID.data;
      ros::param::set("/RobotID",robotID.data);
      pubRobotID.publish(robotID);
      std::cout<<robotID.data<<std::endl;
    }
    RobotIDFile.close();
  }
  else
  {
    ID_Generation:
    RobotIDFile.close();
    printf("文件为空或不存在\n");
    int8_t i=0;
    while (i<10)
    {
      RobotIDFile.open(pathFile,std::ios::out);
      if(RobotIDFile.is_open())
      {
        printf("创建成功，开始写入...\n");
        time_t nowtime;
        time(&nowtime);
        boost::uuids::uuid a_uuid = boost::uuids::random_generator()();
        pathFile.clear();
        robotID.data.clear();
        pathFile =std::to_string(nowtime)+"-"+boost::uuids::to_string(a_uuid);
        RobotIDFile<<pathFile<<std::endl;
        robotID.data=pathFile;
        ros::param::set("/RobotID",robotID.data);
        pubRobotID.publish(robotID);
        printf("写入完成\n");
        pathFile.clear();
        RobotIDFile.close();
        break;
      }
      else
      {
        printf("err:创建失败,再次尝试 [ %d ]/10 \n",i);
        RobotIDFile.close();
        i++;
      }
    }
  }
  while (ros::ok())
  {
    pubRobotID.publish(robotID);
    sleep(3);
  }
  return 0;
}
