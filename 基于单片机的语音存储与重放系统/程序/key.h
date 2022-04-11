#ifndef _KEY_H_
#define _KEY_H_

sbit   key_1 = P3^7;  
sbit   key_2 = P3^6;  
sbit   key_3 = P3^5;  
sbit   key_4 = P3^4;
extern void key_scan(void);
extern unsigned char FunctionCount;
extern unsigned char RecordCount;

extern unsigned char ModeCount;
extern unsigned char NowRec;

extern unsigned int CountRed[4];


#endif 