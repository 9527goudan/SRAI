#include "ros/ros.h"
#include "FRRobot.h"
#include "RobotTypes.h"

#define data_time 3.0

using namespace std;


int main(int argc, char *argv[])

{
  ros::init(argc,argv,"fr3Node");
  ros::NodeHandle nh_;
  FRRobot robot;



  ros::spin();
  return 0;

}
