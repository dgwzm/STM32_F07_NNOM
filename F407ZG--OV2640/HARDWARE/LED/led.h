#ifndef __LED_H
#define __LED_H
#include "sys.h"

//////////////////////////////////////////////////////////////////////////////////	 
 
//LED��������	   
//STM32F4����-�⺯���汾
//�Ա����̣�http://mcudev.taobao.com									  
////////////////////////////////////////////////////////////////////////////////// 	


//LED�˿ڶ���
//#define LED2 PFout(9)	  // 
//#define LED3 PFout(10)	// 


//LED�˿ڶ���
#define LED0 PFout(9)	  // ��ӦLED��ΪD1
#define LED1 PFout(10)	// ��ӦLED��ΪD2

void LED_Init(void);//��ʼ��		 				    
#endif

