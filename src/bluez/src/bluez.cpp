#include"ros/ros.h"
#include"bluetooth/bluetooth.h"
#include"bluetooth/hci.h"
#include"bluetooth/hci_lib.h"

//修改蓝牙名称
void Get_BLE_Name(int socket_BLE)
{
  char *BLE_name = new char[248];
  int ret = hci_read_local_name(socket_BLE,248,BLE_name,0);
  if(0 > ret)
  {
    printf("获取蓝牙设备名称失败!!  ret=%d\n",ret);
    return;
  }
  std::string Name_BLE = BLE_name;
  std::cout<<"蓝牙设备: "<<Name_BLE.c_str()<<std::endl;

  //修改蓝牙名称
  Name_BLE.clear();
  Name_BLE = "SRAI_" + std::to_string(6666);
  ret = hci_write_local_name(socket_BLE,Name_BLE.c_str(),static_cast<int>(Name_BLE.size()));
  if(0 > ret)
  {
    printf("设置蓝牙名称失败！！\n");
    return;
  }
  delete [] BLE_name;

}

int main(int argc, char *argv[])
{
  ros::init(argc,argv,"BLUEZ_NODE");
  ros::NodeHandle BE_nh;

  int deviceID = hci_get_route(nullptr);
  ROS_INFO("deviceID=%d",deviceID);
  int socket_BLE = hci_open_dev(deviceID);
  if(-1 == socket_BLE)
  {
    printf("蓝牙适配器打开失败！！ socket_BLE=%d\n",socket_BLE);
    return -1;
  }

  Get_BLE_Name(socket_BLE);
  ros::spin();
  close(socket_BLE);
  return 0;
}
