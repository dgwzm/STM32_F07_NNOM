#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F4工程模板-库函数版本
//淘宝店铺：http://mcudev.taobao.com									  
////////////////////////////////////////////////////////////////////////////////// 	 

/*下面的方式是通过直接操作库函数方式读取IO*/
#define KEY0 		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9) //PB9
#define KEY1 		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)	//PB8 
#define KEY2 		1                                       //
#define WK_UP 	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)	//PA0

#define KeyShake_Time  5   //去抖动时间，根据扫描定时器确定长度
#define KeyShake_overflow  100   //去抖动时间，根据扫描定时器确定长度

/*下面方式是通过位带操作方式读取IO*/
/*
#define KEY0 		PEin(4)   	//PE4
#define KEY1 		PEin(3)		//PE3 
#define KEY2 		PEin(2)		//P32
#define WK_UP 	PAin(0)		//PA0
*/

#define WKUP_PRES   1
#define KEY0_PRES 	2
#define KEY1_PRES	  3
#define KEY2_PRES	  4


void KEY_Init(void);	//IO初始化

void KEY_Scan(void);//按键扫描函数	

#endif
