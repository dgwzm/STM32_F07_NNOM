#include "key.h"
#include "delay.h" 
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F4����ģ��-�⺯���汾
//�Ա����̣�http://mcudev.taobao.com							  
////////////////////////////////////////////////////////////////////////////////// 	 

//������ʼ������
void KEY_Init(void)
{
	
	GPIO_InitTypeDef  GPIO_InitStructure;

  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOB, ENABLE);//ʹ��GPIOA,GPIOBʱ��
 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8|GPIO_Pin_9; //KEY0 KEY1 ��Ӧ����
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//��ͨ����ģʽ
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100M
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//����
  GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��PB8,9
	
	 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//WK_UP��Ӧ����PA0
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_DOWN ;//����
  GPIO_Init(GPIOA, &GPIO_InitStructure);//��ʼ��GPIOA0
 
} 


//����������
//���ذ���ֵ
//mode:0,��֧��������;1,֧��������;
//0��û���κΰ�������
//1��KEY0����
//2��KEY1����
//3��KEY2���� 
//4��KEY3���� WK_UP
//ע��˺�������Ӧ���ȼ�,KEY0>KEY1>KEY2>KEY3!!

uint8_t Key_Flag=0;//������ֵ

uint8_t  key_up=1;//�������ɿ���־

uint16_t Key_times[3]={0,0,0};//��⵽��������ȥ�Ĵ���

uint16_t Key_Time_out[3]={0,0,0};//�������δ�������£�����Ϊ�Ƕ�����������ʱ����������Ǵ�ֵ



void KEY_Scan(void)
{	 
	
	if(Key_times[0]>0)
	{
		++Key_Time_out[0];
		
		if(Key_Time_out[0]>KeyShake_overflow)//����Ƿ�ʱ
    {
			Key_Time_out[0]=0;//�����ʱ���
			Key_times[0]=0;   //��������Ǵ�
		}
	}
	
	if(Key_times[1]>0)
	{
		++Key_Time_out[1];
		
		if(Key_Time_out[1]>KeyShake_overflow)//����Ƿ�ʱ
    {
			Key_Time_out[1]=0;//�����ʱ���
			Key_times[1]=0;   //��������Ǵ�
		}
	}
	
	if(Key_times[2]>0)
	{
		++Key_Time_out[2];
		
		if(Key_Time_out[2]>KeyShake_overflow)//����Ƿ�ʱ
    {
			Key_Time_out[2]=0;//�����ʱ���
			Key_times[2]=0;   //��������Ǵ�
		}
	}
	
		
	if(KEY0==0||KEY1==0||WK_UP==1)
	{
		
		key_up=0;//��ǰ�а�������
		
    if(WK_UP==1)
			{
				 Key_times[0]++;
				
				 if(Key_times[0]>=KeyShake_Time)
				 { 
					 Key_Time_out[0]=0;//�����ʱ���
					 Key_times[0]=0;//���һ�μ���
				   Key_Flag=1;//����������30mS�Σ���⵽����һֱ�ڰ��£���ȷ���ǰ�������ȥ��

				 }
			}
		
		else if(KEY0==0)
			{	
				 Key_times[1]++;
				
				 if(Key_times[1]>=KeyShake_Time)
				 {
					 Key_Time_out[1]=0;//�����ʱ���
           Key_times[1]=0;//���һ�μ���					 
				   Key_Flag= 2;      //���ذ���ֵ
			 
				 } 
				
			}
		else if(KEY1==0)
			{
				Key_times[2]++;
				
				if(Key_times[2]>=KeyShake_Time)
				 {
					 Key_Time_out[2]=0;//�����ʱ���
           Key_times[2]=0;//���һ�μ���					 
				   Key_Flag= 3;      //���ذ���ֵ
						
				 }	
				
			}
	}
	else if(KEY0==1&&KEY1==1&&WK_UP==0)//���κΰ�������
	{
		
		key_up=1;
		
	}
	
 		
}














