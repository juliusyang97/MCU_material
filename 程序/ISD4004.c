#include"ISD4004.h"
#include <intrins.h>

void delayms(unsigned char ms)// ��ʱ�ӳ��� 
{      
	unsigned char j;
	while(ms--)
	{
		for(j = 0; j < 120; j++);
	}
}

////////////////���������ӳ��򣬷�����ַ��ADDR����////
void play(unsigned int addr)
{  
	unsigned int y;
	SS=0;
	MOSI=0;//���Ϳ�ʼ
	SCLK=0;
	for(y=0;y<8;y++)//�ϵ�
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
	}//���ͽ���
	SS=1;//�ϵ����
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
	}//���͵�ַ����
	MOSI=0;//����
	SCLK=0;
	for(y=0;y<8;y++)//��ָ����ַ��ʼ����
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
	for(y=0;y<8;y++)//�ӵ�ǰ��ַ��ʼ����
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
//////////////////////////¼�������ӳ��򣬵�ַ��ADDR����/////////////////////////
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
	}//���ͽ���
	SS=1;//�ϵ����
	delayms(50);
	delayms(50);
	SS=0;
	MOSI=0;//���͵�ַ
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
	}//���͵�ַ����
	MOSI=0;
	SCLK=0;
	for(y=0;y<8;y++)  //��ָ����ַ��ʼ¼��
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
	for(y=0;y<8;y++) //�ӵ�ǰ��ַ��ʼ¼��
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
	for(y=0;y<8;y++)//ֹͣ��ǰ����
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