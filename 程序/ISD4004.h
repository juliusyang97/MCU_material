#ifndef _ISD4004_H_
#define _ISD4004_H_

#include<reg52.h>

#define ISDPOWERUP      0X25           //ISD4004�ϵ�
#define ISDSTOP         0X10           //ISD4004�µ�
#define OPERSTOP        0X30           //ISD4004ֹͣ��ǰ����
#define PLAYSET         0XE7           //ISD4004��ָ����ַ��ʼ����
#define PLAYCUR         0XF0           //ISD4004�ӵ�ǰ��ַ��ʼ����
#define RECSET          0XA5           //ISD4004��ָ����ַ��ʼ¼��
#define RECCUR          0XB0           //ISD4004�ӵ�ǰ��ַ��ʼ¼��

#define ADDR1STR        0X020           //��һ�׵���ʼ��ַ 
#define ADDR2STR        0X240           //�ڶ��׵���ʼ��ַ 
#define ADDR3STR        0X180           //�����׵���ʼ��ַ 
#define ADDR4STR        0X720           //�����׵���ʼ��ַ 

sbit   SS=P1^5;            //LOW IS ACTIVELY
sbit   MOSI=P1^4;
sbit   MISO=P1^3;
sbit   SCLK=P1^6;

extern void stop();
extern void rec(unsigned int addr);
extern void play(unsigned int addr);


#endif 