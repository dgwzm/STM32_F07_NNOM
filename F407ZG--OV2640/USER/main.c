#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
#include "lcd.h"
#include "image.h" 
#include "timer.h"
#include "ov2640.h"
#include "dcmi.h"
#include "nnom.h"
#include "incep_weights.h"
//#include "ATM128.h"
//#include "qq_logo.h"
//#include "mobilenet_test.h"
//STM32F407������
//����ͷ ʵ�� -�⺯���汾

extern u8 ov_frame;  						//֡��
extern uint8_t Key_Flag;        //������ֵ
u8 Com1SendFlag;                //����1�������ݱ��

u8 ov2640_mode = 0;						//����ģʽ:0,RGB565ģʽ;1,JPEGģʽ

#define jpeg_buf_size 224*224+16 			//����JPEG���ݻ���jpeg_buf�Ĵ�С(*4�ֽ�)
uint8_t getimage[28*28];
__align(4) u16 jpeg_buf[jpeg_buf_size];	//JPEG���ݻ���buf
//u8 get_rgb[224*224];
volatile u32 jpeg_data_len = 0; 			//buf�е�JPEG��Ч���ݳ���
volatile u8 jpeg_data_ok = 0;				//JPEG���ݲɼ���ɱ�־
#ifdef NNOM_USING_STATIC_MEMORY    
uint8_t static_buf[1024*18];//224*224

#endif

//0,����û�вɼ���;
//1,���ݲɼ�����,���ǻ�û����;
//2,�����Ѿ����������,���Կ�ʼ��һ֡����
//JPEG�ߴ�֧���б�
const u16 jpeg_img_size_tbl[][2] =
{
    176, 144,	//QCIF
    160, 120,	//QQVGA
    352, 288,	//CIF
    320, 240,	//QVGA
    640, 480,	//VGA
    800, 600,	//SVGA
    1024, 768,	//XGA
    1280, 1024,	//SXGA
    1600, 1200,	//UXGA
};


const u8*EFFECTS_TBL[7] = {"Normal", "Negative", "B&W", "Redish", "Greenish", "Bluish", "Antique"};	//7����Ч
const u8*JPEG_SIZE_TBL[9] = {"QCIF", "QQVGA", "CIF", "QVGA", "VGA", "SVGA", "XGA", "SXGA", "UXGA"};	//JPEGͼƬ 9�ֳߴ�


//����JPEG����
//���ɼ���һ֡JPEG���ݺ�,���ô˺���,�л�JPEG BUF.��ʼ��һ֡�ɼ�.


void jpeg_data_process(void)
{
	DCMI_Stop();
	jpeg_data_ok=1;

}
//void jpeg_data_process(void)
//{		
//	if(jpeg_data_ok == 0)
//		jpeg_data_ok = 1;
//	if(jpeg_data_ok == 2)				//��һ�ε�jpeg�����Ѿ���������
//		jpeg_data_ok = 0;
//	if(jpeg_data_ok == 0)	//jpeg���ݻ�δ�ɼ���?
//	{
//		LCD_SetCursor(0,0);  
//		LCD_WriteRAM_Prepare();		//��ʼд��GRAM
//		jpeg_data_ok = 1; 				//���JPEG���ݲɼ��갴��,�ȴ�������������
//	}
//	if(jpeg_data_ok == 2)				//��һ�ε�jpeg�����Ѿ���������
//	{
//		DMA2_Stream1->NDTR = jpeg_buf_size;
//		DMA_SetCurrDataCounter(DMA2_Stream1, jpeg_buf_size); //���䳤��Ϊjpeg_buf_size*4�ֽ�
//		DMA_Cmd(DMA2_Stream1, ENABLE);			//���´���
//		jpeg_data_ok = 0;						//�������δ�ɼ�
//	}

//}
void show_pic(int8_t *pic)
{
	u8 temp;
	int num=0;
	int x=0;
	int8_t *pusMsk = pic;

	for(x=0;x<784;x++)
	{	
		temp = *pusMsk;
		if(temp==0)
			LCD_Fast_DrawPoint(x%28,(int)(x/28),WHITE);//????
		else
			LCD_Fast_DrawPoint(x%28,(int)(x/28),BLACK);   //????(?????)
		pusMsk++;
	}
	
}

void two_val(u32 Wide, u32 Height,u8 *pdata,u8 seg_val)
{
	u32 i,j;
	unsigned char picH,picL,R,G,B;
	u16 data,val;
  for(i=0;i<Wide*Height;i++)
	{
		picL=*(pdata+i*2);	
		picH=*(pdata+i*2+1);		
		
		data=picH<<8|picL;
		R = data & 0xF800;
		G = data & 0x07E0;
		B = data & 0x001F;
		val=R+B;//+G;
		if(val>seg_val)
		{
			*(pdata+i)=0xff;
		}
		else
		{
			*(pdata+i)=0x00;
		}
		LCD_Fast_DrawPoint(i%Wide,(int)(i/(Wide)),*(pdata+i)<<8|0x00ff);		
	}
	
}
void resize(u32 In_Wide, u32 In_Height,u32 Out_Wide, u32 Out_Height)
{
	unsigned char picH,picL,R,G,B,m,n,num;
	u16 i,j,k,l;
	u16 data,val,max_val;
	int max=0;
	max_val=30;
	for(k=0;k<28*28;k++)
	{
		num=0;
		for(m=0;m<8;m++)
		{
			for(n=0;n<8;n++)
			{
				max=64*(int)(k/28)*28+(k-(int)(k/28)*28)*8+m*224+n;
				//LCD_Fast_DrawPoint(max%In_Wide,(int)(max/(In_Wide)),static_buf[max]<<8|0x00ff);
				if(jpeg_buf[max]==0x00) //black
					num++;
			}
		}

		if(num>=max_val)
		{
			getimage[k]=127;
			LCD_Fast_DrawPoint(k%Out_Wide+20,(int)(k/(Out_Wide))+260,BLACK);
		}
		else
		{
			getimage[k]=0;
			LCD_Fast_DrawPoint(k%Out_Wide+20,(int)(k/(Out_Wide))+260,GRAY);	
		}
	}
	
}


void Showimage_16(u32 x, u32 y, u8 *pdata)
{
	u8 *u_pdata;
	u32 i,j;
	u16 Wide=10;
	u16 Height=10;
	u32 data_cnt=10;
	unsigned char picH,picL,R,G,B;;
	u16 min=255,max=0,data,val;
	
	Wide = pdata[3] << 8;		
	Wide += pdata[2];			
	
	Height = pdata[5] << 8;		
	Height += pdata[4];			
	u_pdata = &pdata[8];

	for(i=0;i<Wide*Height;i++)
	{
			picL=*(u_pdata+i*2);
			picH=*(u_pdata+i*2+1);
			data=picH<<8|picL;
			LCD_Fast_DrawPoint(i%Wide,(int)(i/(Wide)),data);		
	}
	LCD_ShowNum(30, 240, Wide, 3, 16);
	LCD_ShowNum(60, 240, Height, 3, 16);
	delay_ms(1000);
	for(i=0;i<Wide*Height;i++)
	{
			picL=*(u_pdata+i*2);	
			picH=*(u_pdata+i*2+1);
			data=picH<<8|picL;
			R = data & 0xF800;
			G = data & 0x07E0;
			B = data & 0x001F;
		  val=R+B;//+G;
		  data=data&0xF81F;
			if(val >max)
				max=val;
			if(val<min)
				min=val;
			if(val>=10)
				jpeg_buf[i]=0xff;
			else
				jpeg_buf[i]=0x00;
			LCD_Fast_DrawPoint(i%Wide,(int)(i/(Wide)),data);		
	}

	LCD_ShowNum(90, 240, min, 3, 16);
	LCD_ShowNum(120, 240, max, 3, 16);
	
	delay_ms(1000);
	for(i=0;i<Wide*Height;i++)
	{
			LCD_Fast_DrawPoint(i%Wide,(int)(i/(Wide)),jpeg_buf[i]<<8);		
	}

	resize(224,224,28,28);
	
}

//JPEG����
//JPEG����,ͨ������2���͸�����.


int main_test(void)
{
	u8 t;
	//--------------------------------------
	nnom_model_t* model;
	u8 index=0;
	u8 max=0;
	u8 label_index=0;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	LED_Init();					//��ʼ��LED
	LCD_Init();					//LCD��ʼ��
	KEY_Init();					//������ʼ��
	uart_init(115200);
	TIM3_Int_Init(10000 - 1, 84 - 1); //���ö�ʱ���Ķ�ʱƵ��Ϊ10ms  1�����ж�100��

	POINT_COLOR = RED; //��������Ϊ��ɫ
	LCD_ShowString(30, 130, 200, 16, 16, "OV2640 OK");
	//--------------------------------------
	//Showimage_16(0,0,(u8 *)gImage_C);
	//--------------------------------------
	#ifdef NNOM_USING_STATIC_MEMORYs    
	nnom_set_static_buf(static_buf,sizeof(static_buf));
	
	model=nnom_model_create();  
	#endif
	for (uint16_t i = 0; i < 784; i++)
	{
		nnom_input_data[i] = getimage[i];
	}

	model_run(model);

	for (uint16_t i = 0; i < 10; i++)
	{
		if(max<nnom_output_data[i])
		{
			max=nnom_output_data[i];
			index=i;
		}
	}
	//printf("output:%d max:%d index:%d label:%d data_index:%d\n", num_ide,max,index,label[label_index],label_index);
	LCD_ShowString(60, 270, 200, 16, 16, "Label:");
	LCD_ShowxNum(110, 270, 8, 1, 16,0);
	LCD_ShowString(140, 270, 200, 16, 16, "Pre:");
	LCD_ShowxNum(170, 270, index, 2, 16,0);
	//rgb565_test();
}

int main()
{
	u8 t;
	//--------------------------------------
	nnom_model_t* model;
	u8 index=0;
	u8 label_index=0;
	u32 i;
	u8 val,R,G,B;
	u16 max,min,seg;
  min=250;
	max=0;
	seg=10;
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//����ϵͳ�ж����ȼ�����2
	delay_init(168);  //��ʼ����ʱ����
	LED_Init();					//��ʼ��LED
	LCD_Init();					//LCD��ʼ��
	KEY_Init();					//������ʼ��
	uart_init(115200);
	TIM3_Int_Init(10000 - 1, 84 - 1); //���ö�ʱ���Ķ�ʱƵ��Ϊ10ms  1�����ж�100��

	POINT_COLOR = RED; //��������Ϊ��ɫ
	LCD_ShowString(30, 130, 200, 16, 16, "OV2640 OK");
	while(OV2640_Init())//???OV2640
	{
			LCD_ShowString(30, 130, 240, 16, 16, "OV2640 ERR");
			delay_ms(200);
			LCD_Fill(30, 130, 239, 170, WHITE);
			delay_ms(200);
	}
	#ifdef NNOM_USING_STATIC_MEMORY    
	nnom_set_static_buf(static_buf,sizeof(static_buf));
	
	model=nnom_model_create();  
	#endif
	ov2640_mode=1;
	
	OV2640_RGB565_Mode();	//RGB565??
	
	My_DCMI_Init();			//DCMI??
	DCMI_DMA_Init((u32)&jpeg_buf, jpeg_buf_size, DMA_MemoryDataSize_HalfWord, DMA_MemoryInc_Enable); 
	//DCMI_DMA_Init((u32)&LCD->LCD_RAM, 1, DMA_MemoryDataSize_HalfWord, DMA_MemoryInc_Disable); 
	LCD_Set_Window(0,0,224,320);
	OV2640_OutSize_Set(224, 224);
	DCMI_Start();
	jpeg_data_ok=0;
	Key_Flag=KEY0_PRES;
	label_index=0;
	while(1)
	{
		KEY_Scan();

		if(jpeg_data_ok == 1)	
		{
			jpeg_data_ok=2;
			LCD_SetCursor(0,0);  
			LCD_WriteRAM_Prepare();	
			min=1000;
			max=0;
			seg=10;
			for(i=0;i<224*224;i++)
			{
				//------
				if(Key_Flag==KEY0_PRES)
					LCD->LCD_RAM=jpeg_buf[i];
				//
				R = jpeg_buf[i] & 0xF800;
				G = jpeg_buf[i] & 0x07E0;
				B = jpeg_buf[i] & 0x001F;
				val=B;
				if(val >max)
					max=val;
				if(val<min)
					min=val;
				
				if(val>=seg)
				{
					if(Key_Flag==KEY1_PRES)
						LCD->LCD_RAM=WHITE;//
					jpeg_buf[i]=0xff;
				}
				else
				{
					if((int)(i/(224))<20 || i%224 <10)
					{
						if(Key_Flag==KEY1_PRES)
							LCD->LCD_RAM=WHITE;//
						jpeg_buf[i]=0xff;
					}
					else
					{
						if(Key_Flag==KEY1_PRES)
							LCD->LCD_RAM=BLACK;//
						jpeg_buf[i]=0x00;	
					}
				}
			} 
			resize(224,224,28,28);
			if( Key_Flag== WKUP_PRES)
			{
				for (uint16_t i = 0; i < 784; i++)
				{
					nnom_input_data[i] = getimage[i];
				}
				model_run(model);
				index=0;
				for (uint16_t i = 0; i < 10; i++)
				{
					if(max<nnom_output_data[i])
					{
						max=nnom_output_data[i];
						index=i;
					}
				}
//			LCD_ShowString(80, 270, 200, 16, 16, "Label:");
//			LCD_ShowxNum(110, 270, 2, 2, 16,0);
				LCD_ShowString(100, 270, 200, 16, 16, "Pre:");
				LCD_ShowxNum(160, 270, index, 2, 16,0);

				Key_Flag=KEY0_PRES;
			}
			
			LCD_ShowString(10, 230, 200, 16, 16, "max:");
			LCD_ShowxNum(40, 230, max, 3, 16,0);
			
			LCD_ShowString(80, 230, 200, 16, 16, "min:");
			LCD_ShowxNum(110, 230, min, 3, 16,0);
			
			LCD_ShowString(150, 230, 200, 16, 16, "seg:");
			LCD_ShowxNum(180, 230, seg, 3, 16,0);

			DMA2_Stream1->NDTR = jpeg_buf_size;
			DMA_SetCurrDataCounter(DMA2_Stream1, jpeg_buf_size);
			DCMI_Start();
		}
//			

	}
	return 0;
}
//1?