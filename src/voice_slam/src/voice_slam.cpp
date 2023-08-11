#include"ros/ros.h"
#include"actionlib/client/simple_action_client.h"
#include"actionlib/client/terminal_state.h"
#include"actionlib/client/simple_client_goal_state.h"
#include"move_base_msgs/MoveBaseAction.h"
#include"std_msgs/String.h"
#include"thread"
#include"tf/transform_listener.h"
#include"tf/tf.h"
#include"math.h"
#include <geometry_msgs/Twist.h>

class VOICESLAM
{
public:
    VOICESLAM();
    void VoiceCommandCB(const std_msgs::String &Str);
    void ConnectionTF();
    void Get_XY_Yaw();
    void PublishTargetLocation();
    void CoordinateCalculation();
protected:
    ros::NodeHandle VSNH;
    ros::Subscriber SubVoiceCommand;
    ros::Publisher Pub_vel;
    bool msgFig;
    move_base_msgs::MoveBaseGoal Goal;
    double X_New,Y_New,Yaw_New,Len;
    geometry_msgs::Quaternion msg;

    tf::TransformListener listener;
    tf::StampedTransform transform;
};

VOICESLAM::VOICESLAM()
{
  SubVoiceCommand = VSNH.subscribe("/MoveBaseVoice",50,&VOICESLAM::VoiceCommandCB,this);
  Pub_vel = VSNH.advertise<geometry_msgs::Twist>("/cmd_vel",50);
  ros::param::get("/voice_slam_node/AdvanceDistance",Len = 1.0);
  msgFig=false;
}

//建立TF连接
void VOICESLAM::ConnectionTF()
{
  while (ros::ok())
  {
    if(listener.waitForTransform("/map","/base_link",ros::Time(0),ros::Duration(0.2)))
    {
      try
      {
        listener.lookupTransform("/map", "/base_link",ros::Time(0), transform);
      }
      catch (tf::TransformException &ex)
      {
        ROS_ERROR("%s",ex.what());
        usleep(200*1000);
        continue;
      }
      printf("/map --> /base_link 连接成功\n");
    }
    break;
  }
}

//获取当前位置坐标（x,y）及 朝向角度 yaw
void VOICESLAM::Get_XY_Yaw()
{
  X_New = transform.getOrigin().x();
  Y_New = transform.getOrigin().y();

  tf::Quaternion RQ2;
  msg.w=transform.getRotation().getW();
  msg.x=transform.getRotation().getX();
  msg.y=transform.getRotation().getY();
  msg.z=transform.getRotation().getZ();
  tf::quaternionMsgToTF(msg,RQ2);
  double roll,pitch,yaw;
  tf::Matrix3x3(RQ2).getRPY(roll,pitch,yaw);//四元数转欧拉角；以世界坐标系为基坐标系
  Yaw_New = yaw;
}

void VOICESLAM::CoordinateCalculation()
{
  Get_XY_Yaw();
  X_New += Len*cos(Yaw_New);
  Y_New += Len*sin(Yaw_New);
  Goal.target_pose.pose.position.x = X_New;
  Goal.target_pose.pose.position.y = Y_New;
  Goal.target_pose.pose.position.z = 0.0;
  Goal.target_pose.pose.orientation.w = msg.w;
  Goal.target_pose.pose.orientation.x = msg.x;
  Goal.target_pose.pose.orientation.y = msg.y;
  Goal.target_pose.pose.orientation.z = msg.z;
}

void VOICESLAM::VoiceCommandCB(const std_msgs::String &Str)
{
  if(0 == Str.data.compare("go forward"))//前进
  {
    CoordinateCalculation();
    msgFig = true;
  }
  else if (0 == Str.data.compare("go backward"))//后退： 先转向再前进
  {
    Get_XY_Yaw();
    double Yaw = 0.0;
    if(0 > Yaw_New)
      Yaw = Yaw_New + 3.1415926;
    else
      Yaw = Yaw_New - 3.1415926;

    ros::Rate CommSleep(20);
    while (ros::ok())
    {
      geometry_msgs::Twist MY_vel;
      Get_XY_Yaw();
      if(0.0 == std::abs(Yaw - Yaw_New))
      {
        MY_vel.linear.x = 0.0;
        MY_vel.linear.y = 0.0;
        MY_vel.angular.z = 0.0;
        Pub_vel.publish(MY_vel);
      }
      else
      {
        MY_vel.angular.z = -0.5;
        Pub_vel.publish(MY_vel);
      }
      CommSleep.sleep();
      ros::spinOnce();
    }
    CoordinateCalculation();
    msgFig = true;
  }
  else if (0 > Str.data.compare("move_base"))
  {
    //加载站点点位信息
    Goal.target_pose.header.frame_id="map";
    ros::param::get("/"+Str.data+"/positionX",Goal.target_pose.pose.position.x);
    ros::param::get("/"+Str.data+"/positionY",Goal.target_pose.pose.position.y);
    ros::param::get("/"+Str.data+"/positionZ",Goal.target_pose.pose.position.z);
    ros::param::get("/"+Str.data+"/orientationX",Goal.target_pose.pose.orientation.x);
    ros::param::get("/"+Str.data+"/orientationY",Goal.target_pose.pose.orientation.y);
    ros::param::get("/"+Str.data+"/orientationZ",Goal.target_pose.pose.orientation.z);
    ros::param::get("/"+Str.data+"/orientationX",Goal.target_pose.pose.orientation.w);
    msgFig = true;
  }
}

void VOICESLAM::PublishTargetLocation()
{
  actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient("/move_base",true);
  printf("连接movebase_actionServer中\n");
  MoveBaseClient.waitForServer();
  printf("连接movebase_actionServer成功\n");
  ros::Rate SlRat(20);
  while(ros::ok())
  {
      if(msgFig)
      {
          if(MoveBaseClient.getState()==actionlib::SimpleClientGoalState::ACTIVE)
          {
            MoveBaseClient.cancelAllGoals();
            //_clientTcp.cancelGoal();
            MoveBaseClient.stopTrackingGoal();
            printf("目标状态：【%s】\n",MoveBaseClient.getState().toString().c_str());
          }
          else
          {
              Goal.target_pose.header.stamp=ros::Time::now();
              MoveBaseClient.sendGoal(Goal);
              msgFig=false;
          }
      }
      else
      {
          if(!MoveBaseClient.isServerConnected())
          {
              printf("MoveBase-Server掉线，重连中...\n");
              MoveBaseClient.waitForServer();
              printf("MoveBase-Server重连成功\n");
          }
      }
      SlRat.sleep();
      ros::spinOnce();
  }
}

void ROSSpin()
{
    ros::Rate Sleep(20);
    while (ros::ok())
    {
      Sleep.sleep();
      ros::spinOnce();
    }
}

int main(int argc, char *argv[])
{
  ros::init(argc,argv,"VoiceSlamNode");
  VOICESLAM VSlam;
  VSlam.ConnectionTF();
  VSlam.PublishTargetLocation();

  std::thread rosSpin_thread(ROSSpin);//维护回调函数，接受消息
  if(rosSpin_thread.joinable())
    rosSpin_thread.detach();
  rosSpin_thread.join();
  return 0;
}

