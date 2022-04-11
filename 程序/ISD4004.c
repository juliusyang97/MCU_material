#include"ISD4004.h"
#include <intrins.h>

void delayms(unsigned char ms)// 延时子程序 
{      
	unsigned char j;
	while(ms--)
	{
		for(j = 0; j < 120; j++);
	}
}

////////////////放音部分子程序，放音地址由ADDR决定////
void play(unsigned int addr)
{  
	unsigned int y;
	SS=0;
	MOSI=0;//发送开始
	SCLK=0;
	for(y=0;y<8;y++)//上电
	{
		SCLK=0;
		if((ISDPOWERUP>>y)&0x01)MOSI=1;
		else MOSI=0;
		_nop_();
		_nop_();
		_nop_();
		SCLK=1;
		_nop_();
		_nop_();
		_nop_();
	}//发送结束
	SS=1;//上电结束
	delayms(50);
	SS=0;
	SCLK=0;
	for(y=0;y<16;y++)
	{
		SCLK=0;
		if((addr>>y)&0x01)MOSI=1;
		else MOSI=0;
		_nop_();
		_nop_();
		_nop_();
		SCLK=1;
		_nop_();
		_nop_();
		_nop_();
	}//发送地址结束
	MOSI=0;//放音
	SCLK=0;
	for(y=0;y<8;y++)//从指定地址开始放音
	{
		SCLK=0;
		if((PLAYSET>>y)&0x01)MOSI=1;
		else MOSI=0;
		_nop_();
		_nop_();
		_nop_();
		SCLK=1;
		_nop_();
		_nop_();
		_nop_();
	}
	for(y=0;y<8;y++)//从当前地址开始放音
	{
		SCLK=0;
		if((PLAYCUR>>y)&0x01)MOSI=1;
		else MOSI=0;
		_nop_();
		_nop_();
		_nop_();
		SCLK=1;
		_nop_();
		_nop_();
		_nop_();
	}
	SS=1;   
} 
//////////////////////////录音部分子程序，地址由ADDR决定/////////////////////////
void rec(unsigned int addr)               
{  
	unsigned int y; 
	for(y=0;y<8;y++)
	{
		SCLK=0;
		if((ISDPOWERUP>>y)&0x01)MOSI=1;
		else MOSI=0;
		_nop_();
		_nop_();
		_nop_();
		SCLK=1;
		_nop_();
		_nop_();
		_nop_();
	}
	for(y=0;y<8;y++)
	{
		SCLK=1;
		if((ISDPOWERUP>>y)&0x01)MOSI=1;
		else MOSI=0;
		_nop_();
		_nop_();
		_nop_();
		SCLK=0;
		_nop_();
		_nop_();
		_nop_();
	}//发送结束
	SS=1;//上电结束
	delayms(50);
	delayms(50);
	SS=0;
	MOSI=0;//发送地址
	SCLK=0;
	for(y=0;y<16;y++)
	{
		SCLK=0;
		if((addr>>y)&0x01)MOSI=1;
		else MOSI=0;
		_nop_();
		_nop_();
		_nop_();
		SCLK=1;
		_nop_();
		_nop_();
		_nop_();
	}//发送地址结束
	MOSI=0;
	SCLK=0;
	for(y=0;y<8;y++)  //从指定地址开始录音
	{
		SCLK=0;
		if((0xa0>>y)&0x01)MOSI=1;
		else MOSI=0;
		_nop_();
		_nop_();
		_nop_();
		SCLK=1;
		_nop_();
		_nop_();
		_nop_();
	}
	SS=1;
	SS=0;
	MOSI=0;
	SCLK=0;
	for(y=0;y<8;y++) //从当前地址开始录音
	{
		SCLK=0;
		if((0xb0<<y)&0x01)MOSI=1;
		else MOSI=0;
		_nop_();
		_nop_();
		_nop_();
		SCLK=1;
		_nop_();
		_nop_();
		_nop_();
	}
	SS=1;   
}

////////////////////////////////////
////////////////////////////////
void stop()
{
	unsigned char y;
	SS=1;
	SS=0;
	MOSI=0;
	SCLK=0;
	for(y=0;y<8;y++)//停止当前操作
	{
		SCLK=1;
		if((OPERSTOP>>y)&0x01)MOSI=1;
		else MOSI=0;
		_nop_();
		_nop_();
		_nop_();
		SCLK=0;
		_nop_();
		_nop_();
		_nop_();
	}
	SS=1;
}