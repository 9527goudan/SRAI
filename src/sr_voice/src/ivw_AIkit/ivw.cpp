/*
 * @Description: 
 * @version: 
 * @Author: jhfan5
 * @Date: 2021-09-16 17:32:41
 * @LastEditors: liwanqiu wqli15@iflytek.com
 * @LastEditTime: 2022-05-23 13:56:26
 */

#include <fstream>
#include <assert.h>
#include <cstring>
#include <atomic>
#include <unistd.h>
#include "ivw/aikit_biz_api.h"
#include "ivw/aikit_constant.h"
#include "ros/ros.h"
#include "std_msgs/Bool.h"

using namespace std;
using namespace AIKIT;

int times = 1;

void OnOutput(AIKIT_HANDLE* handle, const AIKIT_OutputData* output){
    printf("OnOutput abilityID :%s\n",handle->abilityID);
    printf("OnOutput key:%s\n",output->node->key);
    printf("OnOutput value:%s\n",(char*)output->node->value);    
}
static std::atomic_bool ttsFinished(false);
void OnEvent(AIKIT_HANDLE* handle, AIKIT_EVENT eventType, const AIKIT_OutputEvent* eventValue){
    printf("OnEvent:%d\n",eventType);
    if(eventType == AIKIT_Event_End){
        ttsFinished = true;
    }
}

void OnError(AIKIT_HANDLE* handle, int32_t err, const char* desc){
    printf("OnError:%d\n",err);
}

void ivwIns(){
    AIKIT_ParamBuilder* paramBuilder = nullptr;
    AIKIT_DataBuilder* dataBuilder = nullptr;
    AIKIT_OutputData* output = nullptr;
    AIKIT_HANDLE* handle = nullptr;
    int loopCount = 1;
    int fileSize = 0;
    int readLen = 0;
    FILE * file = nullptr;
    int status = AIKIT_DataBegin;
    char data[320] = {0};
    int index[] = {0};
    int status_continue = AIKIT_DataContinue - 1;
    int writetimes = 0;
    int ret = 0;

    paramBuilder = AIKIT_ParamBuilder::create();

    ttsFinished = false;

    if (times == 1){
    AIKIT_CustomData customData;
    customData.key = "key_word";
    customData.index = 0;
    customData.from = AIKIT_DATA_PTR_PATH;
    customData.value =(void*)"/home/goudan/srbot_ws-C/src/sr_voice/resource/keyword-nhxd.txt";
    customData.len = strlen("/home/goudan/srbot_ws-C/src/sr_voice/resource/keyword-nhxd.txt");
    customData.next = nullptr;
    customData.reserved = nullptr;
    printf("AIKIT_LoadData start!\n");
    ret = AIKIT_LoadData("ef7d69542",&customData);
    printf("AIKIT_LoadData end!\n");
    printf("AIKIT_LoadData:%d\n",ret);
    if(ret != 0){
        goto  exit;
    }
    times++;
    }

    ret = AIKIT_SpecifyDataSet("ef7d69542","key_word",index,1);
    printf("AIKIT_SpecifyDataSet:%d\n",ret);
    if(ret != 0){
        goto  exit;
    }

    // 设置唤醒词门限值
    paramBuilder->param("wdec_param_nCmThreshold","0 0:999",8);
    paramBuilder->param("gramLoad",true);
    ret = AIKIT_Start("ef7d69542",AIKIT_Builder::build(paramBuilder),nullptr,&handle);
    printf("AIKIT_Start:%d\n",ret);
    if(ret != 0){
        goto  exit;
    }

    file = fopen("/home/goudan/srbot_ws-C/src/sr_voice/testAudio/F_F001_xd_10_C1-2_ni3-hao3-xiao3-di2_16bit.wav","rb");
    if(file == nullptr) {
        printf("fopen failed\n");
        goto exit;
    }
    fseek(file,0,SEEK_END);
    fileSize = ftell(file);
    fseek(file,0,SEEK_SET);

    dataBuilder = AIKIT_DataBuilder::create();
    
    while (fileSize > 0) {
        readLen = fread(data,1,sizeof(data),file);
        dataBuilder->clear();
        dataBuilder->audio("wav",data,readLen,status_continue);
        ret = AIKIT_Write(handle,AIKIT_Builder::build(dataBuilder));
        writetimes++;
        if(ret != 0)
        {
            printf("AIKIT_Write:%d\n",ret);
            goto  exit;
        }
       fileSize -= readLen;
    }


    ret = AIKIT_End(handle);

 exit:   
    fclose(file);
    if(file != nullptr){
        file = nullptr;
    }
    if(paramBuilder != nullptr){
        delete paramBuilder;
        paramBuilder = nullptr;
    }

    if(dataBuilder != nullptr){
        delete dataBuilder;
        dataBuilder = nullptr;
    }
}

void TestIVW(){
    int i = 1;

    AIKIT_InitParam param;
    param.appID = "68dc26a6"; //测试appid
    param.apiKey = "ad4b86c7eb1ee0493f5efa1174b9dcc4";
    param.apiSecret = "ZmYwZTRhYzYxMTA4MDJkZTFlZDY1NDZk";
    param.authType = 0;
    //当需要使用纯离线的方式激活时，需要将nullptr换成离线授权文件的所在路径
    param.licenseFile = nullptr;
    //使用时需要将该目录的权限设置为可读&可写，否则可能报错
    param.workDir = "/home/goudan/srbot_ws-C/src/sr_voice/";
    param.batchID = nullptr;
    param.UDID = nullptr;

    AIKIT_Callbacks cbs = {OnOutput,OnEvent,OnError};
    AIKIT_RegisterCallback(cbs);

    //log的打印等级设置为LOG_LVL_OFF时表示关闭log，用户可在调试时设置为LOG_LVL_DEBUG，正式使用时设置为LOG_LVL_OFF
    //设置log的级别，当第二个参数设置LOG_FILE时，意思为将log打印到文件中，同时需要在第三个参数设置文件存储位置
    AIKIT_SetLogInfo(LOG_LVL_DEBUG,LOG_STDOUT,"/home/goudan/srbot_ws-C/src/sr_voice/");
    AIKIT_SetILogOpen(false);
    AIKIT_SetAuthCheckInterval(10);

    int ret = 1;
    ret = AIKIT_Init(&param);
    if(ret != 0){
        printf("AIKIT_Init failed:%d\n",ret);
        goto exit;
    }

    ret = AIKIT_EngineInit("ef7d69542",nullptr);
    if(ret != 0){
        printf("AIKIT_EngineInit failed:%d\n",ret);
        goto exit;
    }
        ivwIns();
        i++;

 exit:   
    AIKIT_UnInit();
}

int main(int argc,char **argv)
{
    ros::init(argc,argv,"IvwVoice");
    ros::NodeHandle Ivw_np;
    ros::Publisher WakeUp_pub=Ivw_np.advertise<std_msgs::Bool>("WakeUp",100);
    TestIVW();
    ros::spin();
    return 0;
}
