/***********************************************************************
  File name:	LCD1602.h
  Author:       Vicky.L   
  Version:      1.0
  Date: 		2011.10.22
  Description:	������ʵ��LCD1602��ʾ�ĵĻ����������ܹ�ʵ�ֳ�ʼ��LCD1602��
  				��LCD1602дָ���LCD1602д���ݡ�����Ļ�ض�λ����ʾһ����
				��������Ļ�ض�λ����ʾһ�����ֵĹ��ܡ�
				���У�LCD1602��8052MCU֮��ӿ�ʾ��ͼ���£�
							 ________________
							|			 P0  |-> LCD_DB
							|			 P1^0|-> LCD_RS
							|			 P1^1|-> LCD_RW
							|			 P1^2|-> LCD_E
							|				 |
							|				 |						 
  Function List��	��Ҫ�����б�ÿ����¼���������������ܼ�Ҫ˵��
		//��ʼ������,��LCD1602���г�ʼ������ʼ������ܽ�����ʾ�����ⲿ����
	1. extern void LCDInit(void);
		//дָ�������LCD1602����дָ�����������Ҫ�ⲿ����  
	2. void LCDWriteCommand(unsigned char command);
		//д���ݺ�������LCD1602����д���ݲ���������Ҫ�ⲿ����		 
	3. void LCDWriteData(unsigned char dat);   
		//��ĳ����Ļλ������ʾһ���ַ�,X��0-15),y(1-2)��datΪ��ʾ�ַ���a����ʽ�����ⲿ����
	4. extern void LCDDispChar(unsigned char x,unsigned char y,unsigned char dat); 
		//��ʱ������д���ݺ�������Ҫ�ʵ���ʱ����������Ҫ�ⲿ����
	5. void DelayN40us(unsigned int n);
		//����Ļĳ��λ������ʾһ�����֣�x(0-15),y(1-2),dat(0-9������ʽ)���ⲿ�ɵ���
	6. extern void LCDDispNum(unsigned char x,unsigned char y,unsigned char dat);
		//����Ļ����ʾһ���ַ������ǵ��ҵ���ֵ���洢�������У�Ϊ��������������ⲿ����
		//x��yΪ��ʼ��ʾ��ַ��x(0-15),y(1-2),string������0��β��
	7. extern void LCDDispString(unsigned char x,unsigned char y,unsigned char *string); 
		//��ĳ����Ļλ����(x,y)λ����ʾһ���޷����������֣����ⲿ���á�
		//X��0-15),y(1-2),dat(0-65536)��
	8. extern void LCDDispNumInt(unsigned char x,unsigned char y,unsigned int dat);  
  History:	�޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ��� 
    1. Date:	2011.10.22	 
       Author:	Vicky.L
       Modification:�������ĵ�
	2. Date:	2011.10.23	 
       Author:	Vicky.L
       Modification:��Ӻ���extern void LCDDispString(unsigned char x,unsigned char y,unsigned char *string);
	3. Date:	2011.10.28	 
       Author:	Vicky.L
       Modification:��Ӻ���extern void LCDDispNumInt(unsigned char x,unsigned char y,unsigned int dat);   
	   
*************************************************************************/
#ifndef _LCD1602_H_
#define _LCD1602_H_

#define LCD_DB     P0	//�����ź� 
sbit   LCD_RS=P1^0;	  //Ƭѡ�ź� 
sbit   LCD_RW=P1^1;	  //��д�ź� 
sbit   LCD_E=P1^2; 	  //ʹ���ź� 

extern void LCDInit(void);
extern void LCDDispString(unsigned char x,unsigned char y,unsigned char *string);   
extern void LCDDispChar(unsigned char x,unsigned char y,unsigned char dat);
extern void LCDDispNum(unsigned char x,unsigned char y,unsigned char dat); 
extern void LCDDispNumInt(unsigned char x,unsigned char y,unsigned int dat);
void LCDWriteCommand(unsigned char command); 
void LCDWriteData(unsigned char dat);	   
void DelayN40us(unsigned int n);

#endif 