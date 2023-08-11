#include <ros/ros.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Quaternion.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf/tf.h>
static double current_yaw = 0;
static ros::Publisher pub;
static ros::Publisher pub1;
static ros::Publisher pub2;
static bool flag = false;

bool ggb(std::string ss, const std_msgs::String::ConstPtr& msg)
{
    return msg->data.find(ss) != std::string::npos;
}
void imu_callback(const sensor_msgs::Imu& imu_msg)
{ 
    tf::Quaternion quat;
    tf::quaternionMsgToTF(imu_msg.orientation, quat);
    double roll, pitch, yaw;
    tf::Matrix3x3(quat).getRPY(roll, pitch, yaw);
    current_yaw = yaw;
}
void cmd_callback(const std_msgs::String::ConstPtr& msg)
{
    geometry_msgs::Twist vel;
    std_msgs::String move;
    ros::Rate rate(10);
    while(ros::ok())
    {
        std_msgs::String output;
        if (ggb("前进",msg) || ggb("往前",msg) || ggb("向前",msg))
        {
            ROS_INFO("执行前进指令"); 
            output.data = "收到指令,开始前进";
            pub2.publish(output);
            for(int i = 0; i < 100; i++) 
            {
                vel.linear.x = (i*0.005);
                pub.publish(vel);
                ros::Duration(0.03).sleep();
            }
            for(int q = 0 ; q < 10; q++)
            {
                vel.linear.x = 0.5;
                pub.publish(vel);
                ros::Duration(0.03).sleep();
            }
            for(int j = 0; j < 100; j++)
            {
                vel.linear.x = (0.5 - j*0.005); 
                pub.publish(vel);
                ros::Duration(0.03).sleep();
            }
            output.data = "前进完毕";
            pub2.publish(output);
        }
        else if (ggb("后退",msg) || ggb("往后",msg) || ggb("向后",msg))
        {
            ROS_INFO("执行后退指令");
            output.data = "收到指令,开始后退";
            pub2.publish(output);
            for(int i = 0; i < 100; i++) 
            {
                vel.linear.x = (-i*0.005);
                pub.publish(vel);
                ros::Duration(0.03).sleep();
            }
            for(int q = 0 ; q < 10; q++)
            {
                vel.linear.x = 0.5;
                pub.publish(vel);
                ros::Duration(0.03).sleep();
            }
            for(int j = 0; j < 100; j++)
            {
                vel.linear.x = (-0.5 + j*0.005); 
                pub.publish(vel);
                ros::Duration(0.03).sleep();
            }
            output.data = "后退完毕";
            pub2.publish(output);
        }
        else if (ggb("左转",msg) || ggb("往左",msg) || ggb("向左",msg))
        {
            flag = true;
            double angle0 = current_yaw;
            ROS_INFO("执行左转指令");
            output.data = "收到指令,开始左转";
            pub2.publish(output);
            while (flag && ros::ok())
            {   
                vel.angular.z = 0.5;
                pub.publish(vel);
                double angle_now = current_yaw;
                ROS_INFO("angle_now - angle0 = %.2f",angle_now - angle0);
                if(abs(angle_now - angle0) > 1.57)
                    break;
                usleep(30*1000);
                rate.sleep();
                ros::spinOnce();
            }
            output.data = "左转完毕";
            pub2.publish(output);   
            vel.angular.z = 0;
            pub.publish(vel); 
        }
        else if (ggb("右转",msg) || ggb("往右",msg) || ggb("向右",msg))
        {   
            flag = true;
            double angle0 = current_yaw;
            ROS_INFO("执行右转指令");
            output.data = "收到指令,开始右转";
            pub2.publish(output);
            while (flag && ros::ok())
            {   
                vel.angular.z = 0.5;
                pub.publish(vel);
                double angle_now = current_yaw;
                if(abs(angle_now - angle0) > 1.57)
                    break;
                usleep(30*1000);
                rate.sleep();
                ros::spinOnce();
            }
            output.data = "右转";
            pub2.publish(output);   
            vel.angular.z = 0;
            pub.publish(vel);      
        }
        else if(ggb("画圈",msg) || ggb("画个圈",msg) || ggb("绕圈",msg) || ggb("圆圈",msg))
        {
            flag = true;
            ROS_INFO("flag = %d" , flag);
            ROS_INFO("执行画圆指令");
            output.data = "收到指令,开始画圈";
            pub2.publish(output);
            while(flag && ros::ok())
            {
                vel.linear.x = 0.5;
                vel.angular.z = 0.5;
                pub.publish(vel);
                //ros::Duration(0.03).sleep();
                rate.sleep();
                ros::spinOnce();
            }
            vel.linear.x = 0;
            vel.angular.z = 0;
            pub.publish(vel);
        }
        else if(ggb("停下",msg) || ggb("停止",msg) || ggb("停住",msg) || ggb("不准动",msg))
        { 
            output.data = "收到指令,停止";
            pub2.publish(output);  
            flag = false;
            vel.linear.x = 0; 
            vel.angular.z = 0;
            pub.publish(vel);
        }
        else if(ggb("a",msg))
        {
            move.data = "move_a";
            pub1.publish(move);
        }
        else if(ggb("b",msg))
        {
            move.data = "move_b";
            pub1.publish(move);
        }
        else if(ggb("c",msg))
        {
            move.data = "move_c";
            pub1.publish(move);
        }
    vel.linear.x = 0.0; 
    vel.linear.y = 0.0; 
    vel.angular.z = 0.0;
    pub.publish(vel);
    }
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;
    pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 50);
    pub1 = nh.advertise<std_msgs::String>("/MoveBaseVoice", 50);
    pub2 = nh.advertise<std_msgs::String>("/TextToVoice",50);
    ros::Subscriber sub_cmd = nh.subscribe("/VoiceCommand", 50, cmd_callback);
    
    ros::Subscriber sub_imu = nh.subscribe("/imu",50,imu_callback);
    ros::Rate Sleep(20);
    ros::spin();
    return 0;
}
