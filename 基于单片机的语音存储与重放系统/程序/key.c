#include<reg52.h>
#include"key.h"
#include"lcd1602.h"
#include"ISD4004.h"
unsigned char FunctionCount=0;
unsigned char RecordCount=0;
unsigned char ModeCount=0;
unsigned char NowRec=0;
unsigned int CountRed[4]={0};
//毫秒延时函数 
void Keydelay(unsigned int z)
{
	unsigned int x,y;
	for(x = z ; x>0 ; x--)
		for(y = 110; y>0 ; y--);
}

void key_scan(void)
{
	if(key_1 == 0)			   //判断第一个按键情况 
	{
		Keydelay(10);
		if(key_1 == 0)	   //按键一
		{
			FunctionCount++;
			if(FunctionCount == 1)
				{LCDDispString(0,1,"Num 2 recording");LCDDispString(1,2,"             ");}
			else if(FunctionCount == 2)
				{LCDDispString(0,1,"Num 3 recording");LCDDispString(1,2,"             ");}
			else if(FunctionCount == 3)
				{LCDDispString(0,1,"Num 4 recording");LCDDispString(1,2,"             ");}
			else if(FunctionCount == 4)
				{LCDDispString(0,1,"   Play Mode    ");
				 if(ModeCount == 0)
					LCDDispString(0,0,"    Mode A    ");
				 else if(ModeCount == 1)
					LCDDispString(0,0,"    Mode B    ");
				 else if(ModeCount == 2)
					LCDDispString(0,0,"    Mode C    ");
				}
			else if(FunctionCount == 5)
			{	LCDDispString(0,1," Play recording ");LCDDispString(1,2,"             ");	 }
			else if(FunctionCount == 6)
			{
				FunctionCount = 0;LCDDispString(0,1,"Num 1 recording");LCDDispString(1,2,"             ");			
			}

			while(!key_1);
		}
	}
	if(key_2 == 0)			   //按键2
	{
		Keydelay(10);
		if(key_2 == 0)
		{
			
			if(FunctionCount == 0)
			{
				LCDDispString(1,2,"   Start      ");
				rec(ADDR1STR);
			}
			else if(FunctionCount == 1)
			{
				LCDDispString(1,2,"   Start      ");
				rec(ADDR2STR);
			}
			else if(FunctionCount == 2)
			{
				LCDDispString(1,2,"   Start      ");
				rec(ADDR3STR);
			}
			else if(FunctionCount == 3)
			{
				LCDDispString(1,2,"   Start      ");
				rec(ADDR4STR);
			}
			else if(FunctionCount == 4)
			{
				 ModeCount++;
				 if(ModeCount == 1)
					 LCDDispString(1,2,"   Mode B    ");
				 else if(ModeCount == 2)
					 LCDDispString(1,2,"   Mode C    ");
				 else if(ModeCount == 3)
				 {ModeCount = 0;LCDDispString(1,2,"   Mode A    ");}
					 
			}
			else if(FunctionCount == 5)//播放
			{
				if(NowRec == 1)
				{LCDDispString(1,2,"   Record 1    ");play(ADDR1STR);}	
				else if(NowRec == 2)
				{LCDDispString(1,2,"   Record 2    ");play(ADDR2STR);}
				else if(NowRec == 3)
				{LCDDispString(1,2,"   Record 3    ");play(ADDR3STR);}
				else if(NowRec == 4)
				{LCDDispString(1,2,"   Record 4    ");play(ADDR4STR);}	
				 if(ModeCount==1) //单曲循环
				 {
				 }
			}
			while(!key_2);
		}
	}
	if(key_3 == 0)			   //按键3 
	{
		Keydelay(10);
		if(key_3 == 0)
		{	
			stop();
			if(FunctionCount == 0)
			{LCDDispString(1,2,"    Stop      ");}
			else if(FunctionCount == 1)
			{LCDDispString(1,2,"    Stop      ");}
			else if(FunctionCount == 2)
			{LCDDispString(1,2,"    Stop      ");}
			else if(FunctionCount == 3)
			{LCDDispString(1,2,"    Stop      ");}
			else if(FunctionCount == 5)
			{LCDDispString(1,2,"    Stop      ");}
			while(!key_3);
		}
	}	

	if(key_4 == 0)			   //按键4
	{
		Keydelay(10);
		if(key_4 == 0)
		{	
			if(FunctionCount == 5 ) //单曲播放
			{
				NowRec ++;
				if(NowRec==5)
				{
					NowRec=0;	
				}
				if(NowRec == 1)
				{LCDDispString(1,2,"   Record 1    ");play(ADDR1STR);}	
				else if(NowRec == 2)
				{LCDDispString(1,2,"   Record 2    ");play(ADDR2STR);}
				else if(NowRec == 3)
				{LCDDispString(1,2,"   Record 3    ");play(ADDR3STR);}
				else if(NowRec == 4)
				{LCDDispString(1,2,"   Record 4    ");play(ADDR4STR);}	
			}
			while(!key_4);
		}
	}
}	