#include"ros/ros.h"
#include"thread"

void ScanningWiFi()
{
  FILE* fp;
    char buffer[1024];

    // 执行 nmcli 命令扫描WiFi
    fp = popen("nmcli device wifi list", "r");
    if (fp == nullptr) {
        fprintf(stderr, "Failed to execute command.\n");
        return ;
    }

    // 读取命令输出并打印扫描结果
    while (fgets(buffer, sizeof(buffer), fp) != nullptr) {
        // 打印单行输出，即WiFi网络信息
        printf("%s", buffer);
    }
    // 关闭文件指针
    pclose(fp);

}

void SYS_WIFI(std::string *_cmd,int *_ret,bool *FIAG)
{
  ScanningWiFi();
  int ret = system(_cmd->c_str());
  if(0 == ret || 512 == ret || 2560 == ret)
  {
    *FIAG = true;
    *_ret = ret;
  }
}

int ConnectToWiFi(std::string *_cmd,double _time = 3.0)
{
  int ret = -1;
  bool ret_0 = false;
  std::thread WIFI(SYS_WIFI,_cmd,&ret,&ret_0);
  if(WIFI.joinable())
    WIFI.detach();

  double Time_0,Tim_1;
  Tim_1 = Time_0 = ros::Time::now().toSec();
  while (_time > (Tim_1 - Time_0))
  {
    Tim_1 = ros::Time::now().toSec();
    if(ret_0)
      break;
    usleep(80*1000);
  }
  if(WIFI.joinable())
    WIFI.join();
  return ret;
}


int main(int argc, char *argv[])
{
  ros::init(argc,argv,"NetWiFiNode_1");
  ros::NodeHandle WiFiNH;
  printf("退出： wifi name='esc'\n");

  while (ros::ok())
  {
    std::string SSID,PASSWORD,CMD;
    printf("wifi name: ");
    std::cin>>SSID;
    if(0 == SSID.compare("esc"))
      break;
    printf("\npassword: ");
    std::cin>>PASSWORD;
    CMD.clear();
    CMD = "nmcli device wifi connect " + SSID +" password " + PASSWORD;

    int reslut = ConnectToWiFi(&CMD,5.0);
    printf("reslut = %d\n",reslut);
  }
  return 0;
}
