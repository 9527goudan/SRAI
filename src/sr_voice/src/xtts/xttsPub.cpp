/*  测试 */
#include"ros/ros.h"
#include"std_msgs/String.h"

int main(int argc, char *argv[])
{
  ros::init(argc,argv,"XttsPub");
  ros::NodeHandle xttsPub_np;
  ros::Publisher Xtts_pub=xttsPub_np.advertise<std_msgs::String>("/TextToVoice",100);

  std_msgs::String textTostring;
  textTostring.data="上海锵玫人工智能科技有限公司（曾用名：上海锵梅网络科技有限公司），成立于2018年，位于上海市，是一家以从事软件和信息技术服务业为主的企业。企业注册资本500万人民币，实缴资本303.444578万人民币，并已于2021年完成了天使轮，交易金额数百万人民币。";

  Xtts_pub.publish(textTostring);
  sleep(20);

  return 0;
}
