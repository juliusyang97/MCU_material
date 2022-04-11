/***********************************************************************
  File name:	LCD1602.h
  Author:       Vicky.L   
  Version:      1.0
  Date: 		2011.10.22
  Description:	本程序实现LCD1602显示的的基本函数。能够实现初始化LCD1602、
  				对LCD1602写指令、对LCD1602写数据、在屏幕特定位置显示一个字
				符、在屏幕特定位置显示一个数字的功能。
				其中，LCD1602和8052MCU之间接口示意图如下：
							 ________________
							|			 P0  |-> LCD_DB
							|			 P1^0|-> LCD_RS
							|			 P1^1|-> LCD_RW
							|			 P1^2|-> LCD_E
							|				 |
							|				 |						 
  Function List：	主要函数列表，每条记录包括函数名及功能简要说明
		//初始化函数,对LCD1602进行初始化，初始化后才能进行显示，可外部调用
	1. extern void LCDInit(void);
		//写指令函数，对LCD1602进行写指令操作，不需要外部调用  
	2. void LCDWriteCommand(unsigned char command);
		//写数据函数，对LCD1602进行写数据操作，不需要外部调用		 
	3. void LCDWriteData(unsigned char dat);   
		//在某个屏幕位置上显示一个字符,X（0-15),y(1-2)，dat为显示字符‘a’形式，可外部调用
	4. extern void LCDDispChar(unsigned char x,unsigned char y,unsigned char dat); 
		//延时函数，写数据和命令需要适当延时操作，不需要外部调用
	5. void DelayN40us(unsigned int n);
		//在屏幕某个位置上显示一个数字，x(0-15),y(1-2),dat(0-9数字形式)，外部可调用
	6. extern void LCDDispNum(unsigned char x,unsigned char y,unsigned char dat);
		//在屏幕上显示一串字符，考虑到我的数值均存储于数组中，为方便而作，允许外部调用
		//x、y为起始显示地址，x(0-15),y(1-2),string必须以0结尾。
	7. extern void LCDDispString(unsigned char x,unsigned char y,unsigned char *string); 
		//在某个屏幕位置上(x,y)位置显示一个无符号整形数字，可外部调用。
		//X（0-15),y(1-2),dat(0-65536)。
	8. extern void LCDDispNumInt(unsigned char x,unsigned char y,unsigned int dat);  
  History:	修改历史记录列表，每条修改记录应包括修改日期、修改者及修改内容简述 
    1. Date:	2011.10.22	 
       Author:	Vicky.L
       Modification:创建本文档
	2. Date:	2011.10.23	 
       Author:	Vicky.L
       Modification:添加函数extern void LCDDispString(unsigned char x,unsigned char y,unsigned char *string);
	3. Date:	2011.10.28	 
       Author:	Vicky.L
       Modification:添加函数extern void LCDDispNumInt(unsigned char x,unsigned char y,unsigned int dat);   
	   
*************************************************************************/
#ifndef _LCD1602_H_
#define _LCD1602_H_

#define LCD_DB     P0	//数据信号 
sbit   LCD_RS=P1^0;	  //片选信号 
sbit   LCD_RW=P1^1;	  //读写信号 
sbit   LCD_E=P1^2; 	  //使能信号 

extern void LCDInit(void);
extern void LCDDispString(unsigned char x,unsigned char y,unsigned char *string);   
extern void LCDDispChar(unsigned char x,unsigned char y,unsigned char dat);
extern void LCDDispNum(unsigned char x,unsigned char y,unsigned char dat); 
extern void LCDDispNumInt(unsigned char x,unsigned char y,unsigned int dat);
void LCDWriteCommand(unsigned char command); 
void LCDWriteData(unsigned char dat);	   
void DelayN40us(unsigned int n);

#endif 