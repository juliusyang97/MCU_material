/////////ISD4004语音播放部分/////////////////////////////
////当按下P3.5键时，从指定地址开始录音
/// 当按下P3.6键时，从指定地址开始放音
/// 当按下P3.7键时，停止当前的操作

#include <reg52.h>

#include "LCD1602.h"
#include "ISD4004.h"
#include "key.h"
unsigned int a,b;
unsigned char flag=0;
void main(void)
{  
	LCDInit(); 
	flag = 0;
	EX0=1;					  //开外部中断0
	IT0=1;					  //设置为下降沿触发方式
	IE0=1;					  //开外部中断0
	while(1)
	{
		key_scan();	
	} 
}

void timer0(void) interrupt 0 //计数器0中断	 
{
	if(FunctionCount == 5 && ModeCount==1)//单曲循环
	{
		if(NowRec == 1 ) //第一首歌曲
		{	LCDDispString(1,2,"   Record 1    ");play(ADDR1STR);}
		if(NowRec == 2) //第2首歌曲
		{	LCDDispString(1,2,"   Record 2    ");play(ADDR2STR);}
		if(NowRec == 3) //第3首歌曲
		{	LCDDispString(1,2,"   Record 3    ");play(ADDR3STR);}
		if(NowRec == 4) //第4首歌曲
		{	LCDDispString(1,2,"   Record 4    ");play(ADDR4STR);}
	}
	else if(FunctionCount == 5 && ModeCount==2)//全循环
	{
		if(NowRec == 4) //第4首歌曲
		{	LCDDispString(1,2,"   Record 4    ");NowRec=1;play(ADDR4STR);}
		else if(NowRec == 3) //第3首歌曲
		{	LCDDispString(1,2,"   Record 3    ");NowRec=4;play(ADDR3STR);}
		else if( NowRec == 2) //第2首歌曲
		{	LCDDispString(1,2,"   Record 2    ");NowRec=3;play(ADDR2STR);}
		else if(NowRec == 1) //第一首歌曲
		{	LCDDispString(1,2,"   Record 1    ");NowRec=2;play(ADDR1STR);}
	}	 
}