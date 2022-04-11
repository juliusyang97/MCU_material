#ifndef _ISD4004_H_
#define _ISD4004_H_

#include<reg52.h>

#define ISDPOWERUP      0X25           //ISD4004上电
#define ISDSTOP         0X10           //ISD4004下电
#define OPERSTOP        0X30           //ISD4004停止当前操作
#define PLAYSET         0XE7           //ISD4004从指定地址开始放音
#define PLAYCUR         0XF0           //ISD4004从当前地址开始放音
#define RECSET          0XA5           //ISD4004从指定地址开始录音
#define RECCUR          0XB0           //ISD4004从当前地址开始录音

#define ADDR1STR        0X020           //第一首的起始地址 
#define ADDR2STR        0X240           //第二首的起始地址 
#define ADDR3STR        0X180           //第三首的起始地址 
#define ADDR4STR        0X720           //第四首的起始地址 

sbit   SS=P1^5;            //LOW IS ACTIVELY
sbit   MOSI=P1^4;
sbit   MISO=P1^3;
sbit   SCLK=P1^6;

extern void stop();
extern void rec(unsigned int addr);
extern void play(unsigned int addr);


#endif 