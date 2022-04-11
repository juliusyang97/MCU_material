#include<reg52.h>
#include"lcd1602.h"

/*********************************************************
  Function:       void DelayN40us(unsigned int n)
  Description:    延时函数，延时40us的整数倍，传入值n代表延时
  				  时间到n *40us，不能实现准确延时，只能实现大
				  概时间的延时，利用的是指令实现延时功能。
  Calls:          没有调用其它函数
  Called By:      void LCDWriteCommand(unsigned char dat);
  				  void LCDWriteData(unsigned char dat);
  Input:          unsigned int n  --- 用于延时时间的确定，取值、
  				  为1~65535
  Output:         无
  Return:         无
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
  Description:    液晶初始化函数,对LCD1602进行初始化操作，
  				  在每一次实用液晶前必须用到的，外部可调用
				  函数。
  Calls:          void LCDWriteCommand(unsigned char dat);
  				  DelayN40us(unsigned int n);
  Called By:      main();或其他
  Input:          无
  Output:         无
  Return:         无
***********************************************************/
void LCDInit(void)	
{
	LCDWriteCommand(0x38);/*设置8位格式，2行，5x7*/
	LCDWriteCommand(0x38);/*设置8位格式，2行，5x7*/
	LCDWriteCommand(0x38);/*设置8位格式，2行，5x7，有的液晶做的不好，写三遍保险！！！！*/ 
	LCDWriteCommand(0x0c);/*整体显示，关光标，不闪烁*/ 
	LCDWriteCommand(0x06);/*设定输入方式，增量不移位*/
	LCDWriteCommand(0x01);/*清除屏幕显示*/	  
	DelayN40us(100);		/*清屏延时*/ 
}
/*********************************************************
  Function:       void LCDWriteCommand(unsigned char dat);
  Description:    写命令函数，对LCD1602内部寄存器进行操作。
  Calls:          DelayN40us(unsigned int n);
  Called By:      void LCDInit(void);
  				  void LCDDispChar(unsigned char x,unsigned char y,unsigned char dat);
				  void LCDDispNum(unsigned char x,unsigned char y,unsigned char dat);	
  Input:          unsigned char dat --- 写入的命令
  Output:         无
  Return:         无
***********************************************************/
void LCDWriteCommand(unsigned char dat)
{
	LCD_DB=dat;
	LCD_RS=0;/*选择写指令*/	 
	LCD_RW=0;/*写入指令值*/	 
	LCD_E=1; /*使能LCD1602*/ 	 
	LCD_E=0;
	DelayN40us(1);/*写命令延时*/   
}
/*********************************************************
  Function:       void LCDWriteData(unsigned char dat);
  Description:    写数据函数，将数据写入LCD1602中。
  Calls:          DelayN40us(unsigned int n);
  Called By:      void LCDInit(void);
  				  void LCDDispChar(unsigned char x,unsigned char y,unsigned char dat);
				  void LCDDispNum(unsigned char x,unsigned char y,unsigned char dat);	
  Input:          unsigned char dat --- 写入的数据
  Output:         无
  Return:         无
***********************************************************/
void LCDWriteData(unsigned char dat)	  //写数据函数 
{
	LCD_DB=dat;
	LCD_RS=1;/*选择写数据*/	  
	LCD_RW=0;/*写入数据值*/	  
	LCD_E=1; /*使能LCD1602*/  
	LCD_E=0;
	DelayN40us(1);/*写数据延时*/ 
}
/*********************************************************
  Function:       void LCDDispChar(unsigned char x,unsigned char y,unsigned char dat);
  Description:    在某个屏幕位置上(x,y)位置显示一个字符，可外部调用。
  Calls:          LCDWriteCommand(unsigned char dat);
  				  void LCDWriteData(unsigned char dat);
  Called By:      main();及其他
  Input:          X（0-15),y(1-2),dat为显示字符‘a’形式。
  Output:         无
  Return:         无
***********************************************************/
void LCDDispChar(unsigned char x,unsigned char y,unsigned char dat)
{
	unsigned char address;
	if(y==1)
	         address=0x80+x;	 /*显示在第一排的时候的x的地址*/ 
	else
	         address=0xc0+x;	 /*显示在第二排的时候的x的地址*/ 
	LCDWriteCommand(address);	 /*输入地址*/ 
	LCDWriteData(dat);		 	 /*输入数据*/ 
}
/*********************************************************
  Function:       void LCDDispNum(unsigned char x,unsigned char y,unsigned char dat);
  Description:    在某个屏幕位置上(x,y)位置显示一个数字，可外部调用。
  Calls:          LCDWriteCommand(unsigned char dat);
  				  void LCDWriteData(unsigned char dat);
  Called By:      main();及其他
  Input:          X（0-15),y(1-2),dat(0-9)。
  Output:         无
  Return:         无
***********************************************************/
void LCDDispNum(unsigned char x,unsigned char y,unsigned char dat)
{
	unsigned char address;
	if(y==1)
	         address=0x80+x;	 /*显示在第一排的时候的x的地址*/ 
	else
	         address=0xc0+x;	 /*显示在第二排的时候的x的地址*/ 
	LCDWriteCommand(address);	 /*输入地址*/ 
	LCDWriteData(dat+48);		 /*输入数据*/ 
}
/*********************************************************
  Function:       void LCDDispString(unsigned char x,unsigned char y,unsigned char *string)
  Description:    在屏幕上显示一串字符，考虑到我的数值均存储于数组中，为方便而作，允许外部调用
  Calls:          void LCDDispChar(unsigned char x,unsigned char y,unsigned char dat);
  Called By:      main();及其他
  Input:          X（0-15),y(1-2),string为任意字符串，但是必须以0结尾。
  Output:         无
  Return:         无
***********************************************************/
void LCDDispString(unsigned char x,unsigned char y,unsigned char *string)
{
	while(*string != 0)	           /*没有检测到字符串结尾时*/
	{
		LCDDispChar(x,y,*string++);/*逐个显示字符串*/
		x++;					   /*行地址加1*/
	}
}
/*********************************************************
  Function:       void LCDDispNumInt(unsigned char x,unsigned char y,unsigned int dat);
  Description:    在某个屏幕位置上(x,y)位置显示一个无符号整形数字，可外部调用。
  Calls:          LCDDispNum(unsigned char x,unsigned char y,unsigned char dat);
  Called By:      main();及其他
  Input:          X（0-15),y(1-2),dat(0-65536)。
  Output:         无
  Return:         无
***********************************************************/
void LCDDispNumInt(unsigned char x,unsigned char y,unsigned int dat)
{
	unsigned char temp[5],i = 0,j=0;/*分离万千百十个各个位临时存储*/
	temp[0] = dat/10000%10;
	temp[1] = dat/1000%10;
	temp[2] = dat/100%10;
	temp[3] = dat/10%10;
	temp[4] = dat%10;
	
	while((temp[i] == 0)&&(i!=4)) /*为保证即使传入的数都是0也能显示，加上i！=4*/
		i++;
	for(j=0;j<5-i;j++)			  /*依次显示各个数*/
   		LCDDispNum(x+j,y,temp[j+i]);
}