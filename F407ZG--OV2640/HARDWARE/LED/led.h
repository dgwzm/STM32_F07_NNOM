#ifndef __LED_H
#define __LED_H
#include "sys.h"

//////////////////////////////////////////////////////////////////////////////////	 
 
//LED驱动代码	   
//STM32F4工程-库函数版本
//淘宝店铺：http://mcudev.taobao.com									  
////////////////////////////////////////////////////////////////////////////////// 	


//LED端口定义
//#define LED2 PFout(9)	  // 
//#define LED3 PFout(10)	// 


//LED端口定义
#define LED0 PFout(9)	  // 对应LED灯为D1
#define LED1 PFout(10)	// 对应LED灯为D2

void LED_Init(void);//初始化		 				    
#endif

