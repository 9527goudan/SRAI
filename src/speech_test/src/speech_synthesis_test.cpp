#include"ros/ros.h"
#include"std_msgs/String.h"

void Printf()
{
  printf("===============================================\n");
  printf("===============================================\n");
  printf("        1:主人，小白在这里\n");
  printf("        2:小白能为你做什么呢\n");
  printf("        3:主人是世界上最帅的人\n");
  printf("        4:对不起，小白没听懂主人意思\n");
  printf("        5:stop 66666\n");
  printf("        6:退出\n");
  printf("===============================================\n");
  printf("===============================================\n");
}


int main(int argc, char *argv[])
{
  ros::init(argc,argv,"SpeechSynthesis");
  ros::NodeHandle Syn_np;
  ros::Publisher strPub = Syn_np.advertise<std_msgs::String>("/TextToVoice",100);
  std_msgs::String MyMsg;
  int ret = 0,ret1 = 0;
  Printf();
  ros::Rate _Sleep(50);
  while (ros::ok())
  {
    printf("输入：");
    std::cin>>ret;
    //std::cout<<std::endl;
    switch (ret)
    {
    case 1:MyMsg.data = "主人，小白在这里";
           ret1 = 1;
           break;
    case 2:MyMsg.data = "小白能为你做什么呢";
           ret1 = 1;
           break;
    case 3:MyMsg.data = "上海锵玫人工智能科技有限公司（曾用名：上海锵梅网络科技有限公司），成立于2018年，位于上海市，是一家以从事软件和信息技术服务业为主的企业。企业注册资本500万人民币，实缴资本303.444578万人民币，并已于2021年完成了天使轮，交易金额数百万人民币。";
           ret1 = 1;
           break;
    case 4:MyMsg.data = "对不起，小白没听懂主人意思";
           ret1 = 1;
           break;
    case 5:MyMsg.data = "小白正在工作，请注意避让";
           ret1 = 1;
           break;
    case 6:ret1 = 0;break;
    }
    if(ret1 == 1)
    {
      strPub.publish(MyMsg);
      _Sleep.sleep();
      MyMsg.data.clear();
      ret1 = 0;
    }
    else
      break;
    usleep(200*1000);
  }
  return 0;
}
