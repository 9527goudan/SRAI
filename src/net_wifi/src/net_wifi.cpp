#include <ros/ros.h>
#include <serial/serial.h>
#include <jsoncpp/json/json.h>
#include <thread>
#include <ifaddrs.h>

//设置串口号及波特率，其它保持默认设置
void BT_SerialSet(serial::Serial *Serial)
{
  std::string Port{};
  int Baudrate = 0;
  ros::param::get("/NetWiFiNode/Port",Port="/dev/ttyUSB0");
  ros::param::get("/NetWiFiNode/Baudrate",Baudrate=115200);
  Serial->setPort(Port);
  Serial->setBaudrate(static_cast<uint32_t>(Baudrate));
  serial::Timeout to = serial::Timeout::simpleTimeout(1000);
  Serial->setTimeout(to);
}

//获取串口设置信息
void CoutSerialSet(serial::Serial *Serial)
{
  std::cout<<"  getPort  : "<<Serial->getPort()<<std::endl;
  std::cout<<"getBaudrate: "<<Serial->getBaudrate()<<std::endl;
  std::cout<<"getBytesize: "<<Serial->getBytesize()<<std::endl;
  std::cout<<"getStopbits: "<<Serial->getStopbits()<<std::endl;
  std::cout<<"getTimeout : "<<Serial->getTimeout().max()<<std::endl;
}

//获取网卡名称
void Get_NIC_Name()
{
  struct ifaddrs* ifaddrList = nullptr;
  if(-1 == getifaddrs(&ifaddrList))
  {
    std::cerr<<"网卡名称获取失败\n";
    return;
  }
  for(;ifaddrList != nullptr;ifaddrList = ifaddrList->ifa_next)
  {
    if(nullptr == ifaddrList->ifa_addr)
      continue;
    if(AF_INET == ifaddrList->ifa_addr->sa_family)
      std::cout<<"网卡设备："<<ifaddrList->ifa_name<<std::endl;
  }
  freeifaddrs(ifaddrList);
}

//先扫描wifi，才能发现wifi进行连接
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

/*功能：连接wifi，超时未连接上退出
 * param1:nmcli 连接wifi命令
 * param2：超时时间，默认3.0秒
 * return： -1：超时，密码错误；0：wifi连接成功；512：wifi密码为空；2560：未发现wifi（wifi名称有误）
*/
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

/*
 * 功能：读取串口数据，连接wifi
 * param:打开的串口地址
*/
void SerialRead(serial::Serial *Serial)
{
  std::string ReadBuff;
  while (ros::ok())
  {
    ReadBuff.clear();
    size_t ret = Serial->read(ReadBuff,1024);
    //std::cout<<"ReadBuff:"<<ReadBuff<<std::endl;
    Serial->flushInput();
    if(0 < ret)
    {
      Json::Value readRoot;
      Json::Reader readBuffToJosn;
      if(readBuffToJosn.parse(ReadBuff,readRoot))
      {
        //std::cout<<readRoot;
        if(readRoot.isMember("WiFi") && !readRoot.isMember("Activate"))
        {
          std::string SSID,PASSWORD,CMD;
          SSID = readRoot["WiFi"]["SSID"].asString();
          PASSWORD = readRoot["WiFi"]["PASSWORD"].asString();
          CMD = "nmcli device wifi connect " + SSID +" password " + PASSWORD;
          int wifi_ret = ConnectToWiFi(&CMD,6.0);
          readRoot.clear();
          switch (wifi_ret)
          {
           case 0:readRoot["Activate"] = 1;break; //成功连接wifi
           case -1://超时即密码错误
           case 512://无该wifi的密码
           case 2560:readRoot["Activate"] = 0;break;//未发现该wifi
          }
          //反馈结果
          Json::FastWriter JsonToString;
          ReadBuff.clear();
          ReadBuff = JsonToString.write(readRoot);
          ReadBuff = "uart_blt('" + ReadBuff +"')" + '\r' + '\n';
          Serial->write(ReadBuff);
          /*
           * 重启操作
          */
        }
      }
      else
        printf("JSON数据格式解析失败！！！\n");
    }
    usleep(200*1000);
  }
}

int main(int argc, char *argv[])
{
  ros::init(argc,argv,"NetWiFiNode");
  ros::NodeHandle netWiFi_NH;
  serial::Serial ESP32_BT;

  BT_SerialSet(&ESP32_BT);
  CoutSerialSet(&ESP32_BT);
  Get_NIC_Name();
  try
  {
    ESP32_BT.open();
  }
  catch (serial::IOException &Err)
  {
    ROS_ERROR_STREAM("Unable to open port.");
    return -1;
  }

  if(ESP32_BT.isOpen())
    SerialRead(&ESP32_BT);
  else
    ROS_ERROR("serial port error");

  ros::spin();
  return 0;
}
