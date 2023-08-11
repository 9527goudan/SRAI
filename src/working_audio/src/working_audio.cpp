#include"ros/ros.h"
#include"iostream"
#include"thread"
#include"working_audio/state_Woking.h"

static int audio=0;
/********************************
 * *****  开辟线程播放mp3，wav文件
 * *****
 * *****
 * ******************************/
void audio_bf()
{
  ros::Rate auid_loop(40);
  while (audio!=5)
  {
    if(audio==1)
    {
      printf("开始播放\n");
      //system("play sr_app/src/working_audio/audio_frequency/消防车警报器音效.wav ");
      //system("play sr_app/src/working_audio/audio_frequency/火警警报声.mp3 ");
      system("play sr_app/src/working_audio/audio_frequency/qingtian.mp3 ");
    }
    auid_loop.sleep();
  }
}

void CallBacke_Working(working_audio::state_Woking workSta)
{
  printf("workSta:%ld",workSta.stateworking);
  switch (workSta.stateworking)
  {
  case 1:audio=1;printf("audio=%d\n",audio);break;
  case 2:audio=2;printf("暂停播放\n");system("killall -STOP play");break;
  case 3:audio=3;printf("恢复播放\n");system("killall -CONT play");break;
  case 4:audio=4;printf("终止播放\n");system("killall -9 play ");break;
  case 5:audio=5;printf("  退出 \n");system("killall -9 play");break;
  default: printf("错误！！！\n");break;
  }
}

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

int main(int arge,char* argv[])
{
  prin_info();
  ros::init(arge,argv,"working_state");
  ros::NodeHandle work_state;
  ros::Subscriber workingState=work_state.subscribe("work/audio",100,&CallBacke_Working);
  std::thread threadd1(audio_bf);
  //if(threadd1.joinable())
     //threadd1.detach();
  ros::Rate loop_audio(20);
  while (ros::ok())
  {
    if(audio==5)
    {
      threadd1.join();
      return 0;
    }
    ros::spinOnce();
    loop_audio.sleep();
  }
  threadd1.join();
  return 1;
}
