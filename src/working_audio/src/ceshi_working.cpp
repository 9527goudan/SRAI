#include"ros/ros.h"
#include"working_audio/state_Woking.h"

void prin_info(void)
{
  printf("**********************\n");
  printf("**********************\n");
  printf("****  1: 开始播放  ****\n");
  printf("****  2: 暂停播放  ****\n");
  printf("****  3: 恢复播放  ****\n");
  printf("****  4: 终止播放  ****\n");
  printf("****  5: 退出     ****\n");
  printf("**********************\n");
  printf("**********************\n");
}

int main(int argc, char *argv[])
{
  prin_info();
  ros::init(argc,argv,"ceshi_working");
  working_audio::state_Woking ceshi;
  ros::NodeHandle np;
  ros::Publisher pub_workin=np.advertise<working_audio::state_Woking>("work/audio",100);
  int shuru;
  ros::Rate loop(20);
  while (ros::ok())
  {
    printf("输入： ");
    std::cin>>shuru;
    printf("\n");
    if(shuru==5)
    {
      ceshi.stateworking=shuru;
      pub_workin.publish(ceshi);
      sleep(2);
      return  0;
    }
    ceshi.stateworking=shuru;
    pub_workin.publish(ceshi);
    loop.sleep();
  }
  return 0;
}

