#include <IRremote.h>

int a =5; 

#define music_num_MAX 9

#include <SoftwareSerial.h>
//用户自定义部分-----------------

#include <Wire.h>

//EEPROM---------------------
#include <EEPROM.h>
#define EEPROM_write(address, p) {int i = 0; byte *pp = (byte*)&(p);for(; i < sizeof(p); i++) EEPROM.write(address+i, pp[i]);}
#define EEPROM_read(address, p)  {int i = 0; byte *pp = (byte*)&(p);for(; i < sizeof(p); i++) pp[i]=EEPROM.read(address+i);}

struct config_type
{
  int EEPROM_music_num;       //歌曲的数目
  int EEPROM_music_vol;       //歌曲的音量
};

//用户自定义部分------------------------
#include "audio.h"   //"arduino.h"是控制音频文件

boolean music_status = false; //歌曲播放状态
int music_num = 1;    //歌曲序号
int music_vol = 20;             //音量0~30

String dateStr, ret;

boolean key, key_cache;         //定义mp3的开关

unsigned long music_vol_time_cache = 0;
unsigned long music_vol_time = 0;
boolean music_vol_sta = false;



void setup()        //创建无返回值函数
{
  Serial.begin(9600);    //初始化串口通信，并将波特率设置为9600
  //pinMode(A0, INPUT);
  //pinMode(A1, INPUT);
  //EEPROM---------------------

  //初始化mp3模块
  audio_init(DEVICE_TF, MODE_loopOne, music_vol);   //初始化mp3模块

  // u8g.setRot180();  // rotate screen, if required

}

void loop()            //无返回值Loop函数
{   int n = analogRead(A0);        //读取模拟口A0数值
  Serial.println(n);                           

  if (n>= a)
    {   Serial.println("play");   //串口输出 “play”（工作
        audio_play();              //音频工作
      }
      else  //暂停
      {
        Serial.println("pause");   //串口输出 “pause”（暂停）
        audio_pause();              //音频暂停工作
      }
    }
  

void eeprom_WRITE()
{
  config_type config;     // 定义结构变量config，并定义config的内容
  config.EEPROM_music_num = music_num;
  config.EEPROM_music_vol = music_vol;

  EEPROM_write(0, config);  // 变量config存储到EEPROM，地址0写入
}

void eeprom_READ()
{
  config_type config_readback;
  EEPROM_read(0, config_readback);
  music_num = config_readback.EEPROM_music_num;
  music_vol = config_readback.EEPROM_music_vol;
}

//主界面，可自由定义
