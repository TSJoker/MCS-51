#include <reg52.h>
#include <intrins.h>

#define unchar unsigned char

sbit WEI = P2^7;//由原理图知位选在P2-7口
sbit DUAN = P2^6;//由原理图定义段选
unchar keynum = 22;//定义数码管显示数字


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
		0x77,  //"A"
		0x7C,  //"B"
		0x39,  //"C"
		0x5E,  //"D"
		0x79,  //"E"
		0x71,  //"F"
		0x76,  //"H"
		0x38,  //"L"
		0x37,  //"n"
		0x3E,  //"u"
		0x73,  //"P"
		0x5C,  //"o"
		0x40,  //"-"
		0x00,  //熄灭

};
void Delay50us()		//@11.0592MHz
{
	unsigned char i, j;

	_nop_();
	i = 1;
	j = 134;
	do
	{
		while (--j);
	} while (--i);
}
void buttonscan()//定义按键函数
{
	P3 = 0xf0;//进行列扫描
	if (P3 != 0xf0)//判断是否有按键按下
	{
	Delay50us();
	if (P3 != 0xf0)
	{
		switch (P3)//运用switch语句
		{
			case 0xe0 :keynum = 0; break;//第一列按下
			case 0xd0 :keynum = 1; break;//第二列按下
			case 0xb0 :keynum = 2; break;//第三列按下
			case 0x70 :keynum = 3; break;//第四列按下
		}
	
	P3 = 0x0f;//行扫描
		switch (P3)
		{
			case 0x0e :keynum = keynum; break;//第一行按下
			case 0x0d :keynum = keynum + 4; break;//第二行按下
			case 0x0b :keynum = keynum + 8; break;//第三行按下
			case 0x07 :keynum = keynum + 12; break;//第四行按下
		}
		 while (P3 != 0x0f);//按键松开结束
	  	}
	}
	P3 = 0xff;//独立按键扫描
	if  (P3 != 0xff)//判断独立按键是否按下
	{
	Delay50us();
	if  (P3 != 0xff)
	{
		switch (P3)
		{
			case 0xfe :keynum = 16; break;//s2按下
			case 0xfd :keynum = 17; break;//s3按下
			case 0xfb :keynum = 18; break;//s4按下
			case 0xf7 :keynum = 19; break;//s5按下
		}
		while (P3 != 0xff);//按键松开结束
	}
	}	
}
	

void main()
{
	WEI = 1;//位选锁存器打开
	P0 = 0xfe;//定义第一位数码管
	WEI = 0;//锁存位选数据

	DUAN = 1;//打开段选锁存器
	while(1)
	{
		buttonscan();//扫描按键
		P0 = leddata[keynum];//数码管输出数据
	}

}
