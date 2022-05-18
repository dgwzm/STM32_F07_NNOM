void LCD_Draw_Picture(u16 xstr,u16 ystr,u16 xend,u16 yend,u8 *pic)	    //??
{
	u8 temp,t1;
	u16 x_t=xstr,y_t=ystr;//,x=xstr,y=ystr;
	u8 *pusMsk = pic;//480000 65536
	for(y_t=ystr;y_t<yend;)
    {	
			temp = *pusMsk;
			for(t1=0;t1<8;t1++)
			{
				if(temp&0x80)LCD_Fast_DrawPoint(x_t,y_t,POINT_COLOR);//????
				else LCD_Fast_DrawPoint(x_t,y_t,BACK_COLOR);   //????(?????)
				temp<<=1;
				x_t++;
				if(x_t>=xend)
				{
					x_t=xstr;
					y_t++;
					break;
				}
			}
			pusMsk++; 
    }
}
const unsigned char gImage_4[600] = { /* 0X10,0X01,0X00,0X50,0X00,0X3C, */
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,
0XFF,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0XFE,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X3F,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0X80,0X3F,
0X80,0X00,0X00,0X00,0X00,0X00,0X00,0XFE,0X00,0X0F,0XE0,0X00,0X00,0X00,0X00,0X00,
0X00,0XF8,0X00,0X03,0XFF,0X80,0X00,0X00,0X00,0X00,0X01,0XF0,0X00,0X01,0XFF,0XE0,
0X00,0X00,0X00,0X00,0X03,0XE0,0X00,0X00,0XFF,0XF8,0X00,0X00,0X00,0X00,0X03,0XC0,
0X00,0X00,0X7F,0XFC,0X00,0X00,0X00,0X00,0X07,0XC0,0X00,0X00,0X00,0XFF,0X00,0X00,
0X00,0X00,0X07,0X80,0X00,0X00,0X00,0X1F,0X00,0X00,0X00,0X00,0X0F,0X80,0X00,0X00,
0X00,0X0F,0X80,0X00,0X00,0X00,0X3F,0X80,0X00,0X00,0X00,0X07,0XC0,0X00,0X00,0X00,
0XFF,0X80,0X00,0X00,0X00,0X03,0XC0,0X00,0X00,0X03,0XFF,0X00,0X00,0X00,0X00,0X03,
0XC0,0X00,0X00,0X07,0XFE,0X00,0X00,0X00,0X00,0X01,0XE0,0X00,0X00,0X0F,0XE0,0X00,
0X00,0X00,0X00,0X01,0XE0,0X00,0X00,0X0F,0X80,0X00,0X00,0X00,0X00,0X01,0XE0,0X00,
0X00,0X1F,0X00,0X00,0X00,0X00,0X00,0X01,0XE0,0X00,0X00,0X1E,0X00,0X00,0X00,0X00,
0X00,0X01,0XE0,0X00,0X00,0X1E,0X00,0X00,0X00,0X00,0X00,0X01,0XE0,0X00,0X00,0X1C,
0X00,0X00,0X00,0X00,0X00,0X01,0XE0,0X00,0X00,0X1C,0X00,0X00,0X00,0X00,0X00,0X01,
0XE0,0X00,0X00,0X1E,0X00,0X00,0X00,0X00,0X00,0X03,0XC0,0X00,0X00,0X1E,0X00,0X00,
0X00,0X00,0X00,0X03,0XC0,0X00,0X00,0X1F,0X00,0X00,0X00,0X00,0X00,0X07,0XC0,0X00,
0X00,0X0F,0X00,0X00,0X00,0X00,0X00,0X1F,0X80,0X00,0X00,0X0F,0XC0,0X00,0X17,0X80,
0X00,0X3F,0X00,0X00,0X00,0X07,0XF8,0X00,0X7F,0X80,0X00,0XFE,0X00,0X00,0X00,0X03,
0XFF,0X00,0XFF,0X00,0X00,0XFC,0X00,0X00,0X00,0X01,0XFF,0X00,0XFE,0X00,0X00,0XF8,
0X00,0X00,0X00,0X00,0X7E,0X01,0XFC,0X00,0X80,0XE0,0X00,0X00,0X00,0X00,0X00,0X03,
0XF8,0X01,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XF0,0X01,0XC0,0X00,0X00,0X00,
0X00,0X00,0X00,0X07,0XF0,0X03,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0XF3,0X03,
0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XFF,0X07,0XE0,0X00,0X00,0X00,0X00,0X00,
0X00,0X01,0XFE,0X07,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7C,0X07,0XF0,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X78,0X0F,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0XF0,0X0F,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XC0,0X0F,0XF8,0X00,0X00,0X00,
0X00,0X00,0X00,0X01,0X80,0X0F,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X00,0X0F,
0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X06,0X00,0X07,0XF0,0X00,0X00,0X00,0X00,0X00,
0X00,0X04,0X00,0X03,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X08,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,};

const unsigned char gImage_3[600] = { /* 0X10,0X01,0X00,0X50,0X00,0X3C, */
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X30,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X30,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X30,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X30,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X30,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X30,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0X00,
0X00,0X01,0X80,0X00,0X00,0X00,0X00,0X00,0X03,0X80,0X00,0X03,0X80,0X00,0X00,0X00,
0X00,0X00,0X01,0XC0,0X00,0X07,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XC0,0XFE,0X06,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XFF,0X80,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X07,0XFF,0XC0,0X00,0X00,0X00,0X00,0X00,0X03,0XFE,0X0F,0X01,0XE0,0X00,0X00,
0X00,0X00,0X00,0X0F,0XFF,0XFE,0X00,0XF0,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,0XFC,
0X00,0X70,0X00,0X00,0X00,0X00,0X00,0X7E,0X00,0XFC,0X00,0X38,0X00,0X00,0X00,0X00,
0X00,0X78,0X00,0X3C,0X00,0X38,0X00,0X00,0X00,0X00,0X00,0XE0,0X00,0X1F,0XE0,0X18,
0X00,0X00,0X00,0X00,0X01,0XC0,0X00,0X0F,0XFC,0X18,0X7C,0X00,0X00,0X00,0X03,0XC0,
0X00,0X07,0XFE,0X18,0X7E,0X00,0X00,0X00,0X03,0X80,0X00,0X00,0X0F,0X38,0X00,0X00,
0X00,0X00,0X07,0X80,0X00,0X00,0X07,0XF8,0X00,0X00,0X00,0X00,0X0F,0X00,0X00,0X00,
0X03,0XF8,0X00,0X00,0X00,0X00,0X3F,0X00,0X00,0X00,0X01,0XF0,0X00,0X00,0X00,0X00,
0XFF,0X00,0X00,0X00,0X00,0XF0,0X00,0X00,0X00,0X01,0XF8,0X00,0X00,0X00,0X00,0XE0,
0X00,0X00,0X00,0X03,0XC0,0X00,0X00,0X00,0X00,0X60,0X00,0X00,0X00,0X03,0X80,0X00,
0X00,0X00,0X00,0X70,0X00,0X00,0X00,0X07,0X00,0X00,0X00,0X00,0X00,0X7C,0X00,0X00,
0X00,0X07,0X00,0X00,0X00,0X00,0X00,0X7E,0X00,0X00,0X00,0X07,0X00,0X00,0X00,0X00,
0X00,0XF7,0X00,0X00,0X00,0X07,0X00,0X00,0X00,0X00,0X00,0XE1,0X80,0X00,0X00,0X07,
0X00,0X00,0X00,0X00,0X00,0XE0,0X80,0X00,0X00,0X07,0X00,0X00,0X00,0X00,0X01,0XC0,
0X00,0X00,0X00,0X03,0X80,0X00,0X00,0X00,0X03,0XC0,0X00,0X00,0X00,0X01,0XE0,0X00,
0X00,0X00,0X0F,0X80,0X00,0X00,0X00,0X01,0XFE,0X00,0X00,0X00,0X1F,0X00,0X00,0X00,
0X00,0X00,0X7E,0X00,0XC0,0X00,0X3C,0X00,0X00,0X00,0X00,0X00,0X1E,0X01,0XC0,0X00,
0X10,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X03,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0XC0,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X07,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,
0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X30,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X70,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X01,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XF0,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X03,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XE0,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,};

const unsigned char gImage_2[600] = { /* 0X10,0X01,0X00,0X50,0X00,0X3C, */
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X07,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0XFF,0X00,
0X00,0X00,0X00,0X00,0X00,0X01,0XC0,0X7F,0XFF,0X80,0X00,0X00,0X00,0X00,0X00,0X1F,
0XFF,0XFF,0XFF,0XC0,0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,0XF8,0X07,0XF8,0X00,0X00,
0X00,0X00,0X01,0XFF,0XFF,0XF0,0X01,0XFF,0X80,0X00,0X00,0X00,0X03,0XFE,0X1F,0XF0,
0X00,0XFF,0XE0,0X00,0X00,0X00,0X07,0XF0,0X01,0XF8,0X00,0X7F,0XF0,0X00,0X00,0X00,
0X0F,0XC0,0X00,0XFC,0X00,0X1F,0XF8,0X00,0X00,0X00,0X1F,0X80,0X00,0X7F,0XF8,0X00,
0XFC,0X00,0X00,0X00,0X1F,0X00,0X00,0X1F,0XFE,0X00,0X3E,0X00,0X00,0X00,0X3E,0X00,
0X00,0X1F,0XFF,0X80,0X1E,0X00,0X00,0X00,0X7C,0X00,0X00,0X0F,0XFF,0XC0,0X1E,0X00,
0X00,0X00,0X78,0X00,0X00,0X00,0X0F,0XE0,0X0E,0X00,0X00,0X00,0XF8,0X00,0X00,0X00,
0X03,0XF0,0X0F,0X00,0X00,0X00,0XF8,0X00,0X00,0X00,0X01,0XF8,0X0F,0X00,0X00,0X03,
0XF0,0X00,0X00,0X00,0X00,0XF8,0X0F,0X00,0X00,0X1F,0XF0,0X00,0X00,0X00,0X00,0X7C,
0X1E,0X00,0X00,0X3F,0XF0,0X00,0X00,0X00,0X00,0X3C,0X1E,0X00,0X00,0X7F,0XE0,0X00,
0X00,0X00,0X00,0X3C,0X1E,0X00,0X00,0XFE,0X00,0X00,0X00,0X00,0X00,0X1C,0X3E,0X00,
0X01,0XF8,0X00,0X00,0X00,0X00,0X00,0X1E,0X7C,0X00,0X01,0XE0,0X00,0X00,0X00,0X00,
0X00,0X1F,0XF8,0X00,0X01,0XE0,0X00,0X00,0X00,0X00,0X00,0X1F,0XF0,0X00,0X03,0XC0,
0X00,0X00,0X00,0X00,0X00,0X1F,0XE0,0X00,0X03,0XC0,0X00,0X00,0X00,0X00,0X00,0X1F,
0XC0,0X00,0X03,0XC0,0X00,0X00,0X00,0X00,0X00,0X3E,0X00,0X00,0X03,0XC0,0X00,0X00,
0X00,0X00,0X00,0X3C,0X00,0X00,0X03,0XE0,0X00,0X00,0X00,0X00,0X00,0X7C,0X00,0X00,
0X01,0XE0,0X00,0X00,0X00,0X00,0X00,0XF8,0X00,0X00,0X01,0XF0,0X00,0X00,0X00,0X00,
0X01,0XF8,0X00,0X00,0X00,0XF8,0X00,0X00,0X00,0X00,0X03,0XF0,0X00,0X00,0X00,0XFE,
0X00,0X00,0X00,0X00,0X1F,0XE0,0X00,0X00,0X00,0X7F,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,
0X00,0X00,0X00,0X3F,0XFF,0XFF,0XFF,0XFF,0XFF,0X80,0X00,0X00,0X00,0X0F,0XFF,0XFF,
0XFF,0XFF,0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0X0F,0XFF,0X40,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,};

const unsigned char gImage_1[600] = { /* 0X10,0X01,0X00,0X50,0X00,0X3C, */
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X06,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X06,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0E,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X0E,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X0E,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X0E,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X0E,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X06,0X00,0X00,0X00,0X0E,0X00,0X00,0X00,
0X00,0X00,0X07,0X00,0X00,0X00,0X1C,0X00,0X00,0X00,0X00,0X00,0X03,0XC0,0X00,0X00,
0X38,0X00,0X00,0X00,0X00,0X00,0X01,0XE0,0X00,0X00,0X78,0X00,0X00,0X00,0X00,0X00,
0X00,0XE0,0X00,0X00,0X70,0X00,0X00,0X00,0X00,0X00,0X00,0X40,0X3F,0XC0,0X60,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0XFF,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,
0XFF,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0XF8,0X07,0XFF,0XFC,0X00,0X00,0X00,0X00,
0X00,0X0F,0XFF,0X07,0XC0,0X3E,0X00,0X00,0X00,0X00,0X00,0X3F,0XFF,0XFF,0X00,0X1F,
0X00,0X00,0X00,0X00,0X00,0X7F,0XFF,0XFE,0X00,0X0F,0X00,0X00,0X00,0X00,0X00,0XFC,
0X01,0XFC,0X00,0X07,0X80,0X00,0X00,0X00,0X01,0XF0,0X00,0X7C,0X00,0X07,0X80,0X00,
0X00,0X00,0X03,0XE0,0X00,0X3F,0X00,0X07,0X80,0X00,0X00,0X00,0X07,0XC0,0X00,0X1F,
0XFC,0X03,0X83,0X80,0X00,0X00,0X07,0X80,0X00,0X0F,0XFF,0X03,0X83,0XF8,0X00,0X00,
0X0F,0X00,0X00,0X07,0XFF,0XC3,0X83,0XF8,0X00,0X00,0X1E,0X00,0X00,0X01,0X0F,0XE3,
0X81,0X00,0X00,0X00,0X1E,0X00,0X00,0X00,0X03,0XF3,0X80,0X00,0X00,0X00,0X3E,0X00,
0X00,0X00,0X00,0XFF,0X80,0X00,0X00,0X00,0X7C,0X00,0X00,0X00,0X00,0X7F,0X00,0X00,
0X00,0X01,0XFC,0X00,0X00,0X00,0X00,0X3F,0X00,0X00,0X00,0X07,0XFC,0X00,0X00,0X00,
0X00,0X3E,0X00,0X00,0X00,0X0F,0XF8,0X00,0X00,0X00,0X00,0X1E,0X00,0X00,0X00,0X1F,
0X80,0X00,0X00,0X00,0X00,0X1E,0X00,0X00,0X00,0X3E,0X00,0X00,0X00,0X00,0X00,0X1C,
0X00,0X00,0X00,0X3C,0X00,0X00,0X00,0X00,0X00,0X1C,0X00,0X00,0X00,0X78,0X00,0X00,
0X00,0X00,0X00,0X1C,0X60,0X00,0X00,0X78,0X00,0X00,0X00,0X00,0X00,0X1C,0X70,0X00,
0X00,0X70,0X00,0X00,0X00,0X00,0X00,0X1C,0X78,0X00,0X00,0X70,0X00,0X00,0X00,0X00,
0X00,0X1C,0X3C,0X00,0X00,0X78,0X00,0X00,0X00,0X00,0X00,0X3C,0X1C,0X00,0X00,0X78,
0X00,0X00,0X00,0X00,0X00,0X3C,0X0C,0X00,0X00,0X78,0X00,0X00,0X00,0X00,0X00,0X78,
0X00,0X00,0X00,0X3C,0X00,0X00,0X00,0X00,0X00,0XF8,0X00,0X00,0X00,0X1E,0X00,0X00,
0X00,0X00,0X03,0XF0,0X00,0X00,0X00,0X1F,0XC0,0X00,0X00,0X00,0X0F,0XE0,0X00,0X00,
0X00,0X0F,0XFF,0XFF,0XFF,0XFF,0XFF,0XC0,0X00,0X00,0X00,0X03,0XFF,0XFF,0XFF,0XFF,
0XFF,0X00,0X00,0X00,0X00,0X01,0XFF,0XFF,0XFF,0XFF,0XFC,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X7F,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,};

const unsigned char gImage_0[600] = { /* 0X10,0X01,0X00,0X50,0X00,0X3C, */
0X00,0X00,0X00,0X00,0X01,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X03,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X80,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X07,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X07,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0X80,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X07,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X1C,0X00,0X03,0X00,
0X00,0X60,0X00,0X00,0X00,0X00,0X1E,0X00,0X00,0X00,0X00,0XE0,0X00,0X00,0X00,0X00,
0X0F,0X00,0X00,0X00,0X03,0XC0,0X00,0X00,0X00,0X00,0X07,0XC0,0X00,0X00,0X07,0XC0,
0X00,0X00,0X00,0X00,0X07,0XC0,0X00,0X00,0X0F,0X80,0X00,0X00,0X00,0X00,0X03,0XC0,
0X00,0X00,0X0F,0X00,0X00,0X00,0X00,0X00,0X01,0XC0,0X1F,0XE0,0X0E,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X7F,0XFC,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XFF,0XFE,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X07,0XF8,0X3F,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X0F,0XC0,0X0F,0XC0,0X00,
0X00,0X00,0X00,0X00,0X00,0X1F,0X80,0X07,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,
0X00,0X03,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X3E,0X00,0X01,0XF0,0X00,0X00,0X00,
0X00,0X00,0X00,0X3E,0X00,0X00,0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X3C,0X00,0X00,
0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X7C,0X00,0X00,0X78,0X00,0X00,0X00,0X00,0X03,
0XF0,0X7C,0X00,0X00,0X78,0X1F,0X00,0X00,0X00,0X1F,0XF0,0X78,0X00,0X00,0X78,0X3F,
0XE0,0X00,0X00,0X1F,0XF0,0X78,0X00,0X00,0X78,0X3F,0XE0,0X00,0X00,0X00,0X70,0X7C,
0X00,0X00,0X78,0X1C,0X00,0X00,0X00,0X00,0X00,0X7C,0X00,0X00,0X78,0X00,0X00,0X00,
0X00,0X00,0X00,0X7C,0X00,0X00,0XF8,0X00,0X00,0X00,0X00,0X00,0X00,0X3E,0X00,0X00,
0XF0,0X00,0X00,0X00,0X00,0X00,0X00,0X3E,0X00,0X01,0XF0,0X00,0X00,0X00,0X00,0X00,
0X00,0X1F,0X00,0X03,0XE0,0X00,0X00,0X00,0X00,0X00,0X00,0X1F,0X80,0X07,0XE0,0X00,
0X00,0X00,0X00,0X00,0X00,0X0F,0XE0,0X0F,0XC0,0X00,0X00,0X00,0X00,0X00,0X00,0X07,
0XFC,0X7F,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0XFF,0XFF,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X01,0XFF,0XFE,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X7F,0XF8,
0X00,0X00,0X00,0X00,0X00,0X00,0X01,0XC0,0X0F,0XC0,0X0F,0X00,0X00,0X00,0X00,0X00,
0X03,0XC0,0X00,0X00,0X0F,0X00,0X00,0X00,0X00,0X00,0X07,0XC0,0X00,0X00,0X0F,0X80,
0X00,0X00,0X00,0X00,0X07,0X80,0X00,0X00,0X07,0XC0,0X00,0X00,0X00,0X00,0X0F,0X00,
0X00,0X00,0X01,0XE0,0X00,0X00,0X00,0X00,0X1C,0X00,0X00,0X00,0X00,0XE0,0X00,0X00,
0X00,0X00,0X18,0X00,0X03,0X80,0X00,0X60,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0X80,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X07,0X80,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X07,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X80,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X03,0X80,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X03,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X03,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,
0X00,0X00,0X00,0X00,0X00,0X00,0X00,0X00,};


int main(void)
 {	 
		delay_init();	    	 //???????	  
		NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);	 //??NVIC????2:2??????,2??????
		uart_init(115200);	 	//??????115200
		LED_Init();			     //LED?????
		LCD_Init();
		POINT_COLOR=RED;
		LCD_Draw_Picture(0,0,80,60,(u8 *)gImage_0);
		LCD_Draw_Picture(80,0,160,60,(u8 *)gImage_1);
		LCD_Draw_Picture(160,0,240,60,(u8 *)gImage_2);
		LCD_Draw_Picture(240,0,320,60,(u8 *)gImage_3);
	 
		LCD_Draw_Picture(0,60,80,120,(u8 *)gImage_4);
		while(1);
}
