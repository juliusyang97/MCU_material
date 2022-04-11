#include<reg52.h>
#include"lcd1602.h"

/*********************************************************
  Function:       void DelayN40us(unsigned int n)
  Description:    ��ʱ��������ʱ40us��������������ֵn������ʱ
  				  ʱ�䵽n *40us������ʵ��׼ȷ��ʱ��ֻ��ʵ�ִ�
				  ��ʱ�����ʱ�����õ���ָ��ʵ����ʱ���ܡ�
  Calls:          û�е�����������
  Called By:      void LCDWriteCommand(unsigned char dat);
  				  void LCDWriteData(unsigned char dat);
  Input:          unsigned int n  --- ������ʱʱ���ȷ����ȡֵ��
  				  Ϊ1~65535
  Output:         ��
  Return:         ��
***********************************************************/
void DelayN40us(unsigned int n)
{
	unsigned int i;
	unsigned char j;            
	for(i=n;i>0;i--)
		for(j=0;j<2;j++);          
}
/*********************************************************
  Function:       void LCDInit(void);
  Description:    Һ����ʼ������,��LCD1602���г�ʼ��������
  				  ��ÿһ��ʵ��Һ��ǰ�����õ��ģ��ⲿ�ɵ���
				  ������
  Calls:          void LCDWriteCommand(unsigned char dat);
  				  DelayN40us(unsigned int n);
  Called By:      main();������
  Input:          ��
  Output:         ��
  Return:         ��
***********************************************************/
void LCDInit(void)	
{
	LCDWriteCommand(0x38);/*����8λ��ʽ��2�У�5x7*/
	LCDWriteCommand(0x38);/*����8λ��ʽ��2�У�5x7*/
	LCDWriteCommand(0x38);/*����8λ��ʽ��2�У�5x7���е�Һ�����Ĳ��ã�д���鱣�գ�������*/ 
	LCDWriteCommand(0x0c);/*������ʾ���ع�꣬����˸*/ 
	LCDWriteCommand(0x06);/*�趨���뷽ʽ����������λ*/
	LCDWriteCommand(0x01);/*�����Ļ��ʾ*/	  
	DelayN40us(100);		/*������ʱ*/ 
}
/*********************************************************
  Function:       void LCDWriteCommand(unsigned char dat);
  Description:    д���������LCD1602�ڲ��Ĵ������в�����
  Calls:          DelayN40us(unsigned int n);
  Called By:      void LCDInit(void);
  				  void LCDDispChar(unsigned char x,unsigned char y,unsigned char dat);
				  void LCDDispNum(unsigned char x,unsigned char y,unsigned char dat);	
  Input:          unsigned char dat --- д�������
  Output:         ��
  Return:         ��
***********************************************************/
void LCDWriteCommand(unsigned char dat)
{
	LCD_DB=dat;
	LCD_RS=0;/*ѡ��дָ��*/	 
	LCD_RW=0;/*д��ָ��ֵ*/	 
	LCD_E=1; /*ʹ��LCD1602*/ 	 
	LCD_E=0;
	DelayN40us(1);/*д������ʱ*/   
}
/*********************************************************
  Function:       void LCDWriteData(unsigned char dat);
  Description:    д���ݺ�����������д��LCD1602�С�
  Calls:          DelayN40us(unsigned int n);
  Called By:      void LCDInit(void);
  				  void LCDDispChar(unsigned char x,unsigned char y,unsigned char dat);
				  void LCDDispNum(unsigned char x,unsigned char y,unsigned char dat);	
  Input:          unsigned char dat --- д�������
  Output:         ��
  Return:         ��
***********************************************************/
void LCDWriteData(unsigned char dat)	  //д���ݺ��� 
{
	LCD_DB=dat;
	LCD_RS=1;/*ѡ��д����*/	  
	LCD_RW=0;/*д������ֵ*/	  
	LCD_E=1; /*ʹ��LCD1602*/  
	LCD_E=0;
	DelayN40us(1);/*д������ʱ*/ 
}
/*********************************************************
  Function:       void LCDDispChar(unsigned char x,unsigned char y,unsigned char dat);
  Description:    ��ĳ����Ļλ����(x,y)λ����ʾһ���ַ������ⲿ���á�
  Calls:          LCDWriteCommand(unsigned char dat);
  				  void LCDWriteData(unsigned char dat);
  Called By:      main();������
  Input:          X��0-15),y(1-2),datΪ��ʾ�ַ���a����ʽ��
  Output:         ��
  Return:         ��
***********************************************************/
void LCDDispChar(unsigned char x,unsigned char y,unsigned char dat)
{
	unsigned char address;
	if(y==1)
	         address=0x80+x;	 /*��ʾ�ڵ�һ�ŵ�ʱ���x�ĵ�ַ*/ 
	else
	         address=0xc0+x;	 /*��ʾ�ڵڶ��ŵ�ʱ���x�ĵ�ַ*/ 
	LCDWriteCommand(address);	 /*�����ַ*/ 
	LCDWriteData(dat);		 	 /*��������*/ 
}
/*********************************************************
  Function:       void LCDDispNum(unsigned char x,unsigned char y,unsigned char dat);
  Description:    ��ĳ����Ļλ����(x,y)λ����ʾһ�����֣����ⲿ���á�
  Calls:          LCDWriteCommand(unsigned char dat);
  				  void LCDWriteData(unsigned char dat);
  Called By:      main();������
  Input:          X��0-15),y(1-2),dat(0-9)��
  Output:         ��
  Return:         ��
***********************************************************/
void LCDDispNum(unsigned char x,unsigned char y,unsigned char dat)
{
	unsigned char address;
	if(y==1)
	         address=0x80+x;	 /*��ʾ�ڵ�һ�ŵ�ʱ���x�ĵ�ַ*/ 
	else
	         address=0xc0+x;	 /*��ʾ�ڵڶ��ŵ�ʱ���x�ĵ�ַ*/ 
	LCDWriteCommand(address);	 /*�����ַ*/ 
	LCDWriteData(dat+48);		 /*��������*/ 
}
/*********************************************************
  Function:       void LCDDispString(unsigned char x,unsigned char y,unsigned char *string)
  Description:    ����Ļ����ʾһ���ַ������ǵ��ҵ���ֵ���洢�������У�Ϊ��������������ⲿ����
  Calls:          void LCDDispChar(unsigned char x,unsigned char y,unsigned char dat);
  Called By:      main();������
  Input:          X��0-15),y(1-2),stringΪ�����ַ��������Ǳ�����0��β��
  Output:         ��
  Return:         ��
***********************************************************/
void LCDDispString(unsigned char x,unsigned char y,unsigned char *string)
{
	while(*string != 0)	           /*û�м�⵽�ַ�����βʱ*/
	{
		LCDDispChar(x,y,*string++);/*�����ʾ�ַ���*/
		x++;					   /*�е�ַ��1*/
	}
}
/*********************************************************
  Function:       void LCDDispNumInt(unsigned char x,unsigned char y,unsigned int dat);
  Description:    ��ĳ����Ļλ����(x,y)λ����ʾһ���޷����������֣����ⲿ���á�
  Calls:          LCDDispNum(unsigned char x,unsigned char y,unsigned char dat);
  Called By:      main();������
  Input:          X��0-15),y(1-2),dat(0-65536)��
  Output:         ��
  Return:         ��
***********************************************************/
void LCDDispNumInt(unsigned char x,unsigned char y,unsigned int dat)
{
	unsigned char temp[5],i = 0,j=0;/*������ǧ��ʮ������λ��ʱ�洢*/
	temp[0] = dat/10000%10;
	temp[1] = dat/1000%10;
	temp[2] = dat/100%10;
	temp[3] = dat/10%10;
	temp[4] = dat%10;
	
	while((temp[i] == 0)&&(i!=4)) /*Ϊ��֤��ʹ�����������0Ҳ����ʾ������i��=4*/
		i++;
	for(j=0;j<5-i;j++)			  /*������ʾ������*/
   		LCDDispNum(x+j,y,temp[j+i]);
}