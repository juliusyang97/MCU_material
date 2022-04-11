/////////ISD4004�������Ų���/////////////////////////////
////������P3.5��ʱ����ָ����ַ��ʼ¼��
/// ������P3.6��ʱ����ָ����ַ��ʼ����
/// ������P3.7��ʱ��ֹͣ��ǰ�Ĳ���

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
	EX0=1;					  //���ⲿ�ж�0
	IT0=1;					  //����Ϊ�½��ش�����ʽ
	IE0=1;					  //���ⲿ�ж�0
	while(1)
	{
		key_scan();	
	} 
}

void timer0(void) interrupt 0 //������0�ж�	 
{
	if(FunctionCount == 5 && ModeCount==1)//����ѭ��
	{
		if(NowRec == 1 ) //��һ�׸���
		{	LCDDispString(1,2,"   Record 1    ");play(ADDR1STR);}
		if(NowRec == 2) //��2�׸���
		{	LCDDispString(1,2,"   Record 2    ");play(ADDR2STR);}
		if(NowRec == 3) //��3�׸���
		{	LCDDispString(1,2,"   Record 3    ");play(ADDR3STR);}
		if(NowRec == 4) //��4�׸���
		{	LCDDispString(1,2,"   Record 4    ");play(ADDR4STR);}
	}
	else if(FunctionCount == 5 && ModeCount==2)//ȫѭ��
	{
		if(NowRec == 4) //��4�׸���
		{	LCDDispString(1,2,"   Record 4    ");NowRec=1;play(ADDR4STR);}
		else if(NowRec == 3) //��3�׸���
		{	LCDDispString(1,2,"   Record 3    ");NowRec=4;play(ADDR3STR);}
		else if( NowRec == 2) //��2�׸���
		{	LCDDispString(1,2,"   Record 2    ");NowRec=3;play(ADDR2STR);}
		else if(NowRec == 1) //��һ�׸���
		{	LCDDispString(1,2,"   Record 1    ");NowRec=2;play(ADDR1STR);}
	}	 
}