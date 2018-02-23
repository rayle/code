#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
 	 


//#define KEY0 PEin(4)   	//PE4
//#define KEY1 PEin(3)	//PE3 
//#define KEY2 PEin(2)	//PE2
//#define WK_UP PAin(0)	//PA0  WK_UP

#define KEY0  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)//读取按键0
#define KEY1  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_2)//读取按键1
#define KEY2  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3)//读取按键2 
#define KEY3  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_4)//读取按键3(WK_UP) 
#define KEY4  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_5)
#define KEY5  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_6)
#define KEY6  GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_7)
#define KEY7  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_4)
#define KEY8  GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)
#define KEY9  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_0)
#define KEY10  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)
#define KEY11  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)
#define KEY12  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)
#define KEY13  GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)

 

#define KEY0_PRES 	1	//KEY0按下
#define KEY1_PRES	2	//KEY1按下
#define KEY2_PRES	3	//KEY2按下
#define KEY3_PRES   4	//KEY_UP按下(即WK_UP/KEY_UP)
#define KEY4_PRES   5	
#define KEY5_PRES   6	
#define KEY6_PRES   7	
#define KEY7_PRES   8	
#define KEY8_PRES   9	
#define KEY9_PRES   10	
#define KEY10_PRES   11	
#define KEY11_PRES   12
#define KEY12_PRES   13	
#define KEY13_PRES   14



void KEY_Init(void);//IO初始化
u8 KEY_Scan(u8);  	//按键扫描函数					    
#endif
