#ifndef __KEY_H
#define __KEY_H	 
#include "sys.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F4����ģ��-�⺯���汾
//�Ա����̣�http://mcudev.taobao.com									  
////////////////////////////////////////////////////////////////////////////////// 	 

/*����ķ�ʽ��ͨ��ֱ�Ӳ����⺯����ʽ��ȡIO*/
#define KEY0 		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_9) //PB9
#define KEY1 		GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_8)	//PB8 
#define KEY2 		1                                       //
#define WK_UP 	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)	//PA0

#define KeyShake_Time  5   //ȥ����ʱ�䣬����ɨ�趨ʱ��ȷ������
#define KeyShake_overflow  100   //ȥ����ʱ�䣬����ɨ�趨ʱ��ȷ������

/*���淽ʽ��ͨ��λ��������ʽ��ȡIO*/
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


void KEY_Init(void);	//IO��ʼ��

void KEY_Scan(void);//����ɨ�躯��	

#endif
