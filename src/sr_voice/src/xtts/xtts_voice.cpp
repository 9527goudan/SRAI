/*
* 语音合成（Text To Speech，TTS）技术能够自动将任意文字实时转换为连续的
* 自然语音，是一种能够在任何时间、任何地点，向任何人提供语音信息服务的
* 高效便捷手段，非常符合信息时代海量数据、动态更新和个性化查询的需求。
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "qtts.h"
#include "msp_cmn.h"
#include "msp_errors.h"
#include"ros/ros.h"
#include"std_msgs/String.h"
#include"jsoncpp/json/json.h"
#include"fstream"
#include"thread"

typedef int SR_DWORD;
typedef short int SR_WORD ;
static int8_t playState=0;
/* wav音频头部格式 */
typedef struct _wave_pcm_hdr
{
	char            riff[4];                // = "RIFF"
	int				size_8;                 // = FileSize - 8
	char            wave[4];                // = "WAVE"
	char            fmt[4];                 // = "fmt "
  int				fmt_size;				// = 下一个结构体的大son小 : 16

	short int       format_tag;             // = PCM : 1
	short int       channels;               // = 通道数 : 1
	int				samples_per_sec;        // = 采样率 : 8000 | 6000 | 11025 | 16000
	int				avg_bytes_per_sec;      // = 每秒字节数 : samples_per_sec * bits_per_sample / 8
	short int       block_align;            // = 每采样点字节数 : wBitsPerSample / 8
	short int       bits_per_sample;        // = 量化比特数: 8 | 16

	char            data[4];                // = "data";
	int				data_size;              // = 纯数据长度 : FileSize - 44 
} wave_pcm_hdr;

/* 默认wav音频头部数据 */
wave_pcm_hdr default_wav_hdr = 
{
	{ 'R', 'I', 'F', 'F' },
	0,
	{'W', 'A', 'V', 'E'},
	{'f', 'm', 't', ' '},
	16,
	1,
	1,
	16000,
	32000,
	2,
	16,
	{'d', 'a', 't', 'a'},
	0  
};
/* 文本合成 */
int text_to_speech(const char* src_text, const char* des_path, const char* params)
{
	int          ret          = -1;
  FILE*        fp           = nullptr;
  const char*  sessionID    = nullptr;
	unsigned int audio_len    = 0;
	wave_pcm_hdr wav_hdr      = default_wav_hdr;
	int          synth_status = MSP_TTS_FLAG_STILL_HAVE_DATA;

  if (nullptr == src_text || nullptr == des_path)
	{
		printf("params is error!\n");
		return ret;
	}
	fp = fopen(des_path, "wb");
  if (nullptr == fp)
	{
		printf("open %s error.\n", des_path);
		return ret;
	}
	/* 开始合成 */
	sessionID = QTTSSessionBegin(params, &ret);
	if (MSP_SUCCESS != ret)
	{
		printf("QTTSSessionBegin failed, error code: %d.\n", ret);
		fclose(fp);
		return ret;
	}
  ret = QTTSTextPut(sessionID, src_text, static_cast<unsigned int>(strlen(src_text)), nullptr);
	if (MSP_SUCCESS != ret)
	{
		printf("QTTSTextPut failed, error code: %d.\n",ret);
		QTTSSessionEnd(sessionID, "TextPutError");
		fclose(fp);
		return ret;
	}
	printf("正在合成 ...\n");
	fwrite(&wav_hdr, sizeof(wav_hdr) ,1, fp); //添加wav音频头，使用采样率为16000
	while (1) 
	{
		/* 获取合成音频 */
		const void* data = QTTSAudioGet(sessionID, &audio_len, &synth_status, &ret);
		if (MSP_SUCCESS != ret)
			break;
    if (nullptr != data)
		{
			fwrite(data, audio_len, 1, fp);
		    wav_hdr.data_size += audio_len; //计算data_size大小
		}
		if (MSP_TTS_FLAG_DATA_END == synth_status)
			break;
	}
	printf("\n");
	if (MSP_SUCCESS != ret)
	{
		printf("QTTSAudioGet failed, error code: %d.\n",ret);
		QTTSSessionEnd(sessionID, "AudioGetError");
		fclose(fp);
		return ret;
	}
	/* 修正wav文件头数据的大小 */
	wav_hdr.size_8 += wav_hdr.data_size + (sizeof(wav_hdr) - 8);
	
	/* 将修正过的数据写回文件头部,音频文件为wav格式 */
	fseek(fp, 4, 0);
	fwrite(&wav_hdr.size_8,sizeof(wav_hdr.size_8), 1, fp); //写入size_8的值
	fseek(fp, 40, 0); //将文件指针偏移到存储data_size值的位置
	fwrite(&wav_hdr.data_size,sizeof(wav_hdr.data_size), 1, fp); //写入data_size的值
	fclose(fp);
  fp = nullptr;
	/* 合成完毕 */
	ret = QTTSSessionEnd(sessionID, "Normal");
	if (MSP_SUCCESS != ret)
	{
		printf("QTTSSessionEnd failed, error code: %d.\n",ret);
	}

	return ret;
}

/* 语音合成参数生成 */
std::string ParamGet()
{
  Json::Value root;
  std::string session_begin_params,paramGet;
  std::ifstream jsonFile;
  ros::param::get("/XttsVoice_node/GM_JsonPath",paramGet);
  jsonFile.open(paramGet,std::ios::in);
  if(jsonFile.is_open())
  {
    paramGet.clear();
    jsonFile>>root;
    for (int8_t i=0;i<=7;i++)
    {
      ros::param::get("/XttsVoice_node/GM"+std::to_string(i),paramGet);
      session_begin_params +=(root["GM"+std::to_string(i)].asString() + "=" + paramGet + ",");
      paramGet.clear();
    }
    ros::param::get("/XttsVoice_node/GM0",paramGet);
    if(paramGet=="purextts")
    {
      paramGet.clear();
      for (int8_t j=0;j<3;j++)
      {
        ros::param::get("/XttsVoice_node/LOCAL"+std::to_string(j),paramGet);
        session_begin_params +=(root["LOCAL"+std::to_string(j)].asString() + "=" + paramGet + ",");
        paramGet.clear();
      }
      std::string ParamVoiceName;
      ros::param::get("/XttsVoice_node/LOCAL3",paramGet);
      ros::param::get("/XttsVoice_node/GM1",ParamVoiceName);

      session_begin_params +=(root["LOCAL3"].asString() + "=" + paramGet + ParamVoiceName + ".jet;"
                             + paramGet + "common.jet");
    }
    else
    {
      for (int8_t j=0;j<2;j++)
      {
        ros::param::get("/XttsVoice_node/CLOUD"+std::to_string(j),paramGet);
        session_begin_params +=(root["CLOUD"+std::to_string(j)].asString() + "=" + paramGet + ",");
        paramGet.clear();
      }
      ros::param::get("/XttsVoice_node/CLOUD2",paramGet);
      session_begin_params +=(root["CLOUD2"].asString() + "=" + paramGet);
      paramGet.clear();
    }
  }
  else
  {
    session_begin_params.clear();
    session_begin_params="NULL";
  }
  jsonFile.close();
  return session_begin_params;
}

static bool PlayState = false;

//语音合成
void TextToVoice(const std_msgs::String &MyText)
{
  ROS_INFO("000000000");
  std::string filename,fileParam,session_begin_params;
  session_begin_params=ParamGet();
  if(0 != std::strcmp("NULL",session_begin_params.c_str()))
  {
    ros::param::get("/XttsVoice_node/GM_filepath",filename);
    ros::param::get("/XttsVoice_node/GM_filename",fileParam);
    filename += fileParam;
    /* 文本合成 */
    printf("开始合成 ...\n");
    int ret = text_to_speech(MyText.data.c_str(), filename.c_str(), session_begin_params.c_str());
    if (MSP_SUCCESS != ret)
    {
      printf("text_to_speech failed, error code: %d.\n", ret);
    }
    printf("合成完毕\n");
    //0:初始状态； 2:播放中； 1：播放结束
    switch (playState)
    {
    case 0:
    case 1:  PlayState = true;
             playState=2;
             break;
    case 2:  system("killall -9 play");
             usleep(50*1000);
             PlayState = true;
             playState=2;
             break;
    }
  }
}


void PlayVoice()
{
  std::string FileName,FileParam,FilePath;
  FilePath ="play ";
  ros::param::get("/XttsVoice_node/GM_filepath",FileName);
  ros::param::get("/XttsVoice_node/GM_filename",FileParam);
  FilePath += (FileName + FileParam);
  while (ros::ok())
  {
    if(PlayState)
    {
      system(FilePath.c_str());
      playState = 1;
      PlayState = false;
    }
    usleep(200*1000);
  }
}


int main(int argc, char* argv[])
{ 
  ros::init(argc,argv,"XttsVoice");
  ros::NodeHandle Xtts_np;
  ros::Subscriber textToVoiceSub=Xtts_np.subscribe("/TextToVoice",100,&TextToVoice);

  std::thread PlayVoiceThread(PlayVoice);
  if(PlayVoiceThread.joinable())
     PlayVoiceThread.detach();

  std::string login_params,appid;
  Xtts_np.getParam("/XttsVoice_node/GM_appid",appid="68dc26a6");
  login_params="appid =" + appid + ", work_dir = .";
  int         ret                  = MSP_SUCCESS;
	/* 用户登录 */
  ret = MSPLogin(nullptr, nullptr, login_params.c_str()); //第一个参数是用户名，第二个参数是密码，第三个参数是登录参数，用户名和密码可在http://www.xfyun.cn注册获取
	if (MSP_SUCCESS != ret)
	{
		printf("MSPLogin failed, error code: %d.\n", ret);
		goto exit ;//登录失败，退出登录
	}
  ROS_INFO("Speech synthesis started successfully");
  //appid=ParamGet();
  //std::cout<<appid<<std::endl;
exit:
  ros::Rate Sleep_(50);
  while (ros::ok())
  {
    Sleep_.sleep();
    ros::spinOnce();
  }
  PlayVoiceThread.join();
	MSPLogout(); //退出登录
	return 0;
}

