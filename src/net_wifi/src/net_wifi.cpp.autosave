#include <ros/ros.h>
#include <serial/serial.h>
#include <random>
#include <thread>

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

void SerialRead(serial::Serial *Serial)
{
  uint8_t *ReadBuff = new uint8_t[1024];

  while (ros::ok())
  {
    memset(ReadBuff,0,1024);
    size_t ret = Serial->read(ReadBuff,1024);
    if(0 != ret && 0xfe ==ReadBuff[0])
    {
      size_t OverallLength = ReadBuff[1];
      //数据总长度与接收长度对比
      if(ret == (OverallLength + 2))
      {
        //数据校验
        int8_t CheckSum = 0x00;
        for (size_t i=0;i<=ret;i++)
          CheckSum += ReadBuff[i];
        if( ReadBuff[ret] == CheckSum)
        {
          //提取WiFi名和密码


        }
        else
        {
          printf("数据错误...\n");
          continue;
        }
      }
      else
      {
        printf("数据段缺失...\n");
        continue;
      }

    }
    else
      Serial->flushOutput();
  }

  delete [] ReadBuff;
}

int main(int argc, char *argv[])
{
  ros::init(argc,argv,"NetWiFiNode");
  ros::NodeHandle netWiFi_NH;
  serial::Serial ESP32_BT;

  BT_SerialSet(&ESP32_BT);
  CoutSerialSet(&ESP32_BT);
  try
  {
    ESP32_BT.open();
  }
  catch (serial::IOException &Err)
  {
    ROS_ERROR_STREAM("Unable to open port.");
    return -1;
  }

  std::thread ESP32_BT_thread(SerialRead,&ESP32_BT);
  if(ESP32_BT_thread.joinable())
    ESP32_BT_thread.detach();

  uint8_t *WitBuff = new uint8_t[1024];
  if(ESP32_BT.isOpen())
  {
    //获取机器人类型，是4G还是wifi
    //**IOT : 物联网  4g/5g
    //WiFi  : 无线局域网
    //ENTIRE: 物联网+无线局域网
    std::string RobotClass{};
    ros::param::get("/NetWiFiNode/RobotClass",RobotClass="MT-NBIOT");
    //生成（0，65536）随机数
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<unsigned long> dis(0,65536);
    unsigned long randNumber = dis(gen);
    RobotClass = "SRAI-" + RobotClass + "-" + std::to_string(randNumber);

    WitBuff[0] = 0xfe;
    WitBuff[1] = static_cast<uint8_t>(RobotClass.size() + 2);
    WitBuff[2] = 0xfd;

    int ArrayLength = 0;
    for (unsigned long i=0;i<=RobotClass.size();i++)
    {
      static int j = 3;
      WitBuff[j] = static_cast<uint8_t>(RobotClass[i]);
      j++;
      ArrayLength = j;
    }
    //计算校验位（计算总和，保留低位）
    for (int i=0;i < ArrayLength; i++)
      WitBuff[ArrayLength] += WitBuff[i];
    //开机3s后才向串口发
    sleep(3);
    ESP32_BT.write(WitBuff,static_cast<size_t>(ArrayLength));
  }
  ros::spin();

  delete [] WitBuff;
  ESP32_BT_thread.join();

  return 0;
}
