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
//#include "mobilenet_test.h"
//STM32F407开发板
//摄像头 实验 -库函数版本

extern u8 ov_frame;  						//帧率
extern uint8_t Key_Flag;//按键键值
u8 Com1SendFlag;//串口1发送数据标记

u8 ov2640_mode = 0;						//工作模式:0,RGB565模式;1,JPEG模式

#define jpeg_buf_size 31*1024  			//定义JPEG数据缓存jpeg_buf的大小(*4字节)

__align(4) u32 jpeg_buf[jpeg_buf_size];	//JPEG数据缓存buf

volatile u32 jpeg_data_len = 0; 			//buf中的JPEG有效数据长度
volatile u8 jpeg_data_ok = 0;				//JPEG数据采集完成标志
#ifdef NNOM_USING_STATIC_MEMORY    
uint8_t static_buf[1024*30];
#endif

//0,数据没有采集完;
//1,数据采集完了,但是还没处理;
//2,数据已经处理完成了,可以开始下一帧接收
//JPEG尺寸支持列表
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


const u8*EFFECTS_TBL[7] = {"Normal", "Negative", "B&W", "Redish", "Greenish", "Bluish", "Antique"};	//7种特效
const u8*JPEG_SIZE_TBL[9] = {"QCIF", "QQVGA", "CIF", "QVGA", "VGA", "SVGA", "XGA", "SXGA", "UXGA"};	//JPEG图片 9种尺寸


//处理JPEG数据
//当采集完一帧JPEG数据后,调用此函数,切换JPEG BUF.开始下一帧采集.


void jpeg_data_process(void)
{
    if(ov2640_mode)//只有在JPEG格式下,才需要做处理.
    {
        if(jpeg_data_ok == 0)	//jpeg数据还未采集完?
        {
            DMA_Cmd(DMA2_Stream1, DISABLE);//停止当前传输
            while (DMA_GetCmdStatus(DMA2_Stream1) != DISABLE) {} //等待DMA2_Stream1可配置
            jpeg_data_len = jpeg_buf_size - DMA_GetCurrDataCounter(DMA2_Stream1); //得到此次数据传输的长度

            jpeg_data_ok = 1; 				//标记JPEG数据采集完按成,等待其他函数处理
        }
        if(jpeg_data_ok == 2)	//上一次的jpeg数据已经被处理了
        {
            DMA2_Stream1->NDTR = jpeg_buf_size;
            DMA_SetCurrDataCounter(DMA2_Stream1, jpeg_buf_size); //传输长度为jpeg_buf_size*4字节
            DMA_Cmd(DMA2_Stream1, ENABLE);			//重新传输
            jpeg_data_ok = 0;						//标记数据未采集
        }
    }
		
	else
	{
		LCD_SetCursor(0,0);  
		LCD_WriteRAM_Prepare();		//开始写入GRAM
	}
		
		
}


//JPEG测试
//JPEG数据,通过串口2发送给电脑.

void jpeg_test(void)
{
	  u32 i,jpgstart,jpglen; 
    //u32 i;
	  u8 headok=0;
    u8 *p;

    u8 effect = 0, saturation = 2, contrast = 2;
    u8 size = 5;		//默认是QVGA 800*600尺寸
    u8 msgbuf[15];	//消息缓存区
    
	  uart_init(921600);		///初始化串口波特率为921600   使通信速度更快，PC软件才能更快的刷新图片，太慢的话，会异常
	
	  LCD_Clear(WHITE);
    POINT_COLOR = RED;
    LCD_ShowString(30, 50, 200, 16, 16, "STM32F4XX");
    LCD_ShowString(30, 70, 200, 16, 16, "OV2640 JPEG Mode");
    LCD_ShowString(30, 100, 200, 16, 16, "KEY0:Contrast");			//对比度
    LCD_ShowString(30, 120, 200, 16, 16, "KEY1:Saturation"); 		//色彩饱和度
    LCD_ShowString(30, 140, 200, 16, 16, "KEY2:Effects"); 			//特效
    LCD_ShowString(30, 160, 200, 16, 16, "KEY_UP:Size");				//分辨率设置
    sprintf((char*)msgbuf, "JPEG Size:%s", JPEG_SIZE_TBL[size]);
		
    LCD_ShowString(30, 180, 200, 16, 16, msgbuf);					//显示当前JPEG分辨率

    OV2640_JPEG_Mode();		//JPEG模式
    My_DCMI_Init();			//DCMI配置
	
    DCMI_DMA_Init((u32)&jpeg_buf, jpeg_buf_size, DMA_MemoryDataSize_Word, DMA_MemoryInc_Enable); //DCMI DMA配置
		
    OV2640_OutSize_Set(jpeg_img_size_tbl[size][0], jpeg_img_size_tbl[size][1]); //设置输出尺寸
		
    DCMI_Start(); 		//启动传输
    
		while(1)
    {

        if(jpeg_data_ok == 1)	//已经采集完一帧图像了
        {
            p = (u8*)jpeg_buf;
					
            LCD_ShowString(30, 210, 210, 16, 16, "Sending JPEG data..."); //提示正在传输数据
						jpglen=0;	//设置jpg文件大小为0
						headok=0;	//清除jpg头标记
						for(i=0;i<jpeg_data_len*4;i++)//查找0XFF,0XD8和0XFF,0XD9,获取jpg文件大小
						{
							if((p[i]==0XFF)&&(p[i+1]==0XD8))//找到FF D8
							{
								jpgstart=i;
								headok=1;	//标记找到jpg头(FF D8)
							}
							if((p[i]==0XFF)&&(p[i+1]==0XD9)&&headok)//找到头以后,再找FF D9
							{
								jpglen=i-jpgstart+2;
								break;
							}
						}
						
						if(jpglen)	//正常的jpeg数据 
						{
							p+=jpgstart;			//偏移到0XFF,0XD8处 
							for(i=0;i<jpglen;i++)	//发送整个jpg文件
							{
								while((USART1->SR&0X40)==0);	//循环发送,直到发送完毕   
								USART1->DR=p[i];  
				
								if(Key_Flag)
								{
									Key_Flag = 0; //清除键值		
									break;
								}
							}  
						}					
            if(Key_Flag)	//有按键按下,需要处理
            {
                LCD_ShowString(30, 210, 210, 16, 16, "Quit Sending data   "); //提示退出数据传输
                switch(Key_Flag)
                {
                case KEY0_PRES:	//对比度设置
                    contrast++;
                    if(contrast > 4)contrast = 0;
                    OV2640_Contrast(contrast);
                    sprintf((char*)msgbuf, "Contrast:%d", (signed char)contrast - 2);
                    break;
                case KEY1_PRES:	//饱和度Saturation
                    saturation++;
                    if(saturation > 4)saturation = 0;
                    OV2640_Color_Saturation(saturation);
                    sprintf((char*)msgbuf, "Saturation:%d", (signed char)saturation - 2);
                    break;
                case KEY2_PRES:	//特效设置
                    effect++;
                    if(effect > 6)effect = 0;
                    OV2640_Special_Effects(effect);//设置特效
                    sprintf((char*)msgbuf, "%s", EFFECTS_TBL[effect]);
                    break;
                case WKUP_PRES:	//JPEG输出尺寸设置
                    size++;
                    if(size > 8)size = 0;
                    OV2640_OutSize_Set(jpeg_img_size_tbl[size][0], jpeg_img_size_tbl[size][1]); //设置输出尺寸
                    sprintf((char*)msgbuf, "JPEG Size:%s", JPEG_SIZE_TBL[size]);
                    break;
                }
                LCD_Fill(30, 180, 239, 190 + 16, WHITE);
                LCD_ShowString(30, 180, 210, 16, 16, msgbuf); //显示提示内容
                delay_ms(800);
								Key_Flag=0;//清除键值

            }
            else LCD_ShowString(30, 210, 210, 16, 16, "Send data complete!!"); //提示传输结束设置
            
						jpeg_data_ok = 2;	//标记jpeg数据处理完了,可以让DMA去采集下一帧了.
        }
    }
}


//RGB565测试
//RGB数据直接显示在LCD上面

void rgb565_test(void)
{

    u8 effect = 0, saturation = 2, contrast = 2;
    u8 scale = 1;		//默认是全尺寸缩放
    u8 msgbuf[15];	//消息缓存区
		u8 index=0;
	  u8 max=0;
		u8 label_index=0;
		uint16_t num_ide=0;
		uint8_t num=0;
		nnom_model_t* model;
		
	  uart_init(115200);		//初始化串口波特率为115200
		#ifdef NNOM_USING_STATIC_MEMORY    
		nnom_set_static_buf(static_buf,sizeof(static_buf));
		#endif
		model=nnom_model_create();
	  LCD_Clear(WHITE);
    POINT_COLOR = RED;
//    LCD_ShowString(30, 50, 200, 16, 16, "STM32F4XX");
//    LCD_ShowString(30, 70, 200, 16, 16, "OV2640 RGB565 Mode");
//    LCD_ShowString(30, 100, 200, 16, 16, "KEY0:Contrast");			//对比度
//    LCD_ShowString(30, 130, 200, 16, 16, "KEY1:Saturation"); 		//色彩饱和度
//    LCD_ShowString(30, 150, 200, 16, 16, "KEY2:Effects"); 			//特效
//    LCD_ShowString(30, 170, 200, 16, 16, "KEY_UP:FullSize/Scale");	//1:1尺寸(显示真实尺寸)/全尺寸缩放
		//(u16 x,u16 y,u16 width,u16 height,u8 size,u8 *p)
		//(u16 x,u16 y,u32 num,u8 len,u8 size,u8 mode)
		
    OV2640_RGB565_Mode();	//RGB565模式
		
    My_DCMI_Init();			//DCMI配置
    DCMI_DMA_Init((u32)&LCD->LCD_RAM, 1, DMA_MemoryDataSize_HalfWord, DMA_MemoryInc_Disable); //DCMI DMA配置

		OV2640_OutSize_Set(lcddev.width, lcddev.height);
    DCMI_Start(); 		//启动传输
    
		while(1)
    {
        //key=KEY_Scan(0);
			
				index=0;
				for (uint16_t i = 0; i < 784; i++)
				{
					nnom_input_data[i] = img[label_index][i];
				}
				model_run(model);
        num_ide++;
				num++;
				max=0;
				for (uint16_t i = 0; i < 10; i++)
				{
					if(max<nnom_output_data[i])
					{
						max=nnom_output_data[i];
						index=i;
					}
				}
				//printf("output:%d max:%d index:%d label:%d data_index:%d\n", num_ide,max,index,label[label_index],label_index);
				LCD_ShowxNum(30, 190, label[label_index], 2, 16,0);
				LCD_ShowxNum(80, 190, index, 2, 16,0);
				label_index++;
				if(label_index>=10)
					label_index=0;
				
				if(num_ide>=4000)
					num_ide=0;
				if(num>=65)
					num=0;
/*
//        if(Key_Flag)
//        {
//            DCMI_Stop(); //停止显示
//            switch(Key_Flag)
//            {
//            case KEY0_PRES:	//对比度设置
//                contrast++;
//                if(contrast > 4)contrast = 0;
//                OV2640_Contrast(contrast);
//                sprintf((char*)msgbuf, "Contrast:%d", (signed char)contrast - 2);
//                break;
//            case KEY1_PRES:	//饱和度Saturation
//                saturation++;
//                if(saturation > 4)saturation = 0;
//                OV2640_Color_Saturation(saturation);
//                sprintf((char*)msgbuf, "Saturation:%d", (signed char)saturation - 2);
//                break;
//            case KEY2_PRES:	//特效设置
//                effect++;
//                if(effect > 6)effect = 0;
//                OV2640_Special_Effects(effect);//设置特效
//                sprintf((char*)msgbuf, "%s", EFFECTS_TBL[effect]);
//                break;
//            case WKUP_PRES:	//1:1尺寸(显示真实尺寸)/缩放
//                scale = !scale;
//                if(scale == 0)
//                {
//                    OV2640_ImageWin_Set((1600 - lcddev.width) / 2, (1200 - lcddev.height) / 2, lcddev.width, lcddev.height); //1:1真实尺寸
//                    OV2640_OutSize_Set(lcddev.width, lcddev.height);
//                    sprintf((char*)msgbuf, "Full Size 1:1");
//                }
//                else
//                {
//                    OV2640_ImageWin_Set(0, 0, 1600, 1200);				//全尺寸缩放
//                    OV2640_OutSize_Set(lcddev.width, lcddev.height);
//                    sprintf((char*)msgbuf, "Scale");
//                }
//                break;
//            }
//            LCD_ShowString(30, 50, 210, 16, 16, msgbuf); //显示提示内容
//            delay_ms(800);
//						Key_Flag=0;//清除键值
//            DCMI_Start();//重新开始传输
//        }
*/
//        //delay_ms(200);
//				
        //if(Com1SendFlag == 1) //定时1秒钟发送一次帧数记录
        //{
        //    printf("frame:%dfps\r\n", ov_frame);	//打印帧率
        //    ov_frame = 0;
        //    Com1SendFlag = 0; //清楚发送标记
        //}
    }
}


int main(void)
{
    u8 t;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
    delay_init(168);  //初始化延时函数
    //model=nnom_model_create();
	   //uart_init(115200);		//初始化串口波特率为115200:串口初始化放到摄像头不同的工作模式中，初始化成对应的波特率

    LED_Init();					//初始化LED
    LCD_Init();					//LCD初始化
    KEY_Init();					//按键初始化

    TIM3_Int_Init(10000 - 1, 84 - 1); //设置定时器的定时频率为10ms  1秒钟中断100次

    POINT_COLOR = RED; //设置字体为红色
	
    LCD_ShowString(30, 50, 200, 16, 16, "STM32F4xx");
    LCD_ShowString(30, 70, 200, 16, 16, "OV2640 TEST");
    LCD_ShowString(30, 90, 200, 16, 16, "2017/5/14");

    while(OV2640_Init())//初始化OV2640
    {
        LCD_ShowString(30, 130, 240, 16, 16, "OV2640 ERR");
        delay_ms(200);
        LCD_Fill(30, 130, 239, 170, WHITE);
        delay_ms(200);
    }
    LCD_ShowString(30, 130, 200, 16, 16, "OV2640 OK");
//		
//		rgb565_test();
	jpeg_test();
}
