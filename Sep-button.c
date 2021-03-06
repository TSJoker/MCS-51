#include <reg52.h>
#include <intrins.h>

#define unchar unsigned char
sbit key_s2 = P3^0;//由原理图定义s2按键，下同
sbit WE = P2^7;
sbit DU = P2^6;
sbit key_s3 = P3^1;
sbit key_s4 = P3^2;
sbit key_s5 = P3^3;
unchar i;//定义一个变量代替要在数码管上显示的数
unchar code leddata[] =
	{ 
	    0x3F,  //"0"
	    0x06,  //"1"
	    0x5B,  //"2"
	    0x4F,  //"3"
	    0x66,  //"4"
	    0x6D,  //"5"
	    0x7D,  //"6"
	    0x07,  //"7"
	    0x7F,  //"8"
	    0x6F,  //"9"
	};
	void Delay20us()		//@11.0592MHz
{
	unsigned char i;

	_nop_();
	_nop_();
	_nop_();
	i = 52;
	while (--i);
}

void main()
{
   WE = 1;
   P0 = 0xfe;
   WE = 0;//定义在第一位数码管显示

   while(1)
   {
   	DU = 1;
	P0 = leddata[i];
	DU = 0;
		if (key_s2 == 0)//判断s2是否按下
		{
			Delay20us();//消除按键抖动
			if (key_s2 == 0)//抖动消除后判断
				i++;//按下后执行自加操作
				if (i == 10)//判断i是否为十
					i = 0;//清零
				while (!key_s2)	;//松开按键后执行
		}
		if (key_s3 == 0)
		{
			Delay20us();
			if (key_s3 == 0)
				if (i > 0)//只在值大于0时执行自减操作
				i--;
				while (!key_s3)	;
		}
		if (key_s4 == 0)
		{
			Delay20us();
			if (key_s4 == 0)
				i+=2;
				if (i > 10)
					i = 1;
					if (i == 10)
						i = 0;
				while (!key_s4)	;
		}
   		if (key_s5 == 0)
		{
			Delay20us();
			if (key_s5 == 0)
				if (i > 1)
				i-=2;
				while (!key_s5)	;
		}
   }

}
