/*
* 语音听写(iFly Auto Transform)技术能够实时地将语音转换成对应的文字。
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include "qisr.h"
#include "msp_cmn.h"
#include "msp_errors.h"
#include "ros/ros.h"
#include "linuxrec.h"
#include "fstream"

typedef struct _UserData {
  int     build_fini; //标识语法构建是否完成
  int     update_fini; //标识更新词典是否完成
  int     errcode; //记录语法构建或更新词典回调错误码
  char    grammar_id[32]; //保存语法构建返回的语法ID
}UserData;


//构建语法回调
int QISBuGRCallBack(int errCode,const char *info,void *userData)
{
  UserData *gram_data = (UserData *)userData;
  if(nullptr != gram_data)
  {
    gram_data->errcode = errCode;
    gram_data->build_fini = 1;
  }
  if(MSP_SUCCESS == errCode && nullptr != info)
  {
    printf("语法构建成功\n");
    if(nullptr != gram_data)
      std::strcpy(gram_data->grammar_id,info);
  }
  else
    printf("语法构建失败 erCode=%d\n",errCode);
  return 0;
}

int buildGrammar(UserData *udata)
{
  char * grContent = new char[1024];
  int ret = -1;
  std::ifstream FileBnf;
  std::string asrResPath,path_;
  path_ = "/home/goudan/srbot_ws-C/src/sr_voice/";
  asrResPath = "engine_type=local,sample_rate=16000,asr_res_path=fo|" + path_ +"bin/msc/res/asr/common.jet,"+ "grm_build_path=" +path_+"bin/msc/res/asr/Grmbuilld";
  FileBnf.open(path_+"bin/wakenUp.bnf",std::ios::in);
  if(FileBnf.is_open())
  {
    printf("文件打开成功\n");
    FileBnf>>grContent;

    int ret = QISRBuildGrammar("bnf",grContent,sizeof (grContent),asrResPath.c_str(),(GrammarCallBack)QISBuGRCallBack,udata);
    if(MSP_SUCCESS != ret)
      printf("QISRBuildGrammar() 调用失败 errCode=%d\n",ret);
  }
  delete [] grContent;
  FileBnf.close();
  return ret;
}

int main(int argc, char *argv[])
{
  ros::init(argc,argv,"VoiceAsr");
  ros::NodeHandle ASRnp;

  UserData udata;

  //用户登陆
  std::string param1 = "appid=68dc26a6,engine_start=asr,asr_res_path=fo|/home/goudan/srbot_ws-C/src/sr_voice/bin/msc/res/asr/common.jet";
  int ret = MSPLogin(nullptr,nullptr,param1.c_str());
  if(MSP_SUCCESS != ret)
  {
    printf("登陆出错，检查参数MSPLogin()\n");
    return -1;
  }
  //离线引擎初始化
  std::string paran2Name,param2Value;
  paran2Name = "engine_start";
  param2Value = "engine_start=asr,asr_res_path=fo|/home/goudan/srbot_ws-C/src/sr_voice/bin/msc/res/asr/common.jet";
  ret = MSPSetParam(paran2Name.c_str(),param2Value.c_str());
  if(MSP_SUCCESS != ret)
  {
    printf("命令词离线引擎初始化失败 ret=%d",ret);
    goto tuichu;
  }
  //构建语法，生成语法ID
  ret = buildGrammar(&udata);
  if(MSP_SUCCESS != ret)
  {
    printf("离线语法构建失败  ret=%d\n",ret);
    goto tuichu;
  }
  //开始识别命令词
 // std::string params = "engine_type=local,sample_rate=16000,asr_threshold=60,asr_res_path=fo|[离线引擎资源路径],grm_build_path=[文件保存路径]，";
  ros::spin();
tuichu:
  //退出登陆
  MSPLogout();
  return 0;
}


