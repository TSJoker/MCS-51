#include <reg52.h>
#include <intrins.h>

#define unchar unsigned char

sbit WEI = P2^7;//由原理图知位选在P2-7口
sbit DUAN = P2^6;//由原理图定义段选

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

	unchar leddata[] =
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
	    0x00  //自定义
 
    };

void main()
{

	while(1)
	{
		Delay50us();
	   WEI = 1;//位选锁存器开
	   P0 = 0xfe;//选择第一位数码管
	   WEI = 0;//锁存位选数据
	
	   DUAN = 1;//打开段选锁存器
	   P0 = 0x06;//0000 0110代表数码管显示数字1
	   DUAN = 0;//锁存段选数据
	
	   Delay50us();
	   WEI = 1;//位选锁存器开
	   P0 = 0xfd;//选择第二位数码管
	   WEI = 0;//锁存位选数据
	
	   DUAN = 1;//打开段选锁存器
	   P0 = 0x5b;//0110 1101代表数码管显示数字2
	   DUAN = 0;//锁存段选数据

	   Delay50us();
	   WEI = 1;//位选锁存器开
	   P0 = 0xfb;//选择第三位数码管
	   WEI = 0;//锁存位选数据
	
	   DUAN = 1;//打开段选锁存器
	   P0 = 0x4F;//0100 1111代表数码管显示数字3
	   DUAN = 0;//锁存段选数据

	   Delay50us();
	   WEI = 1;
	   P0 = 0xf7;
	   WEI = 0;
	
	   DUAN = 1;
	   P0 = leddata[4];
	   DUAN = 0;

	   Delay50us();
	   WEI = 1;
	   P0 = 0xef;
	   WEI = 0;
	
	   DUAN = 1;
	   P0 = leddata[5];
	   DUAN = 0;

	   Delay50us();
	   WEI = 1;
	   P0 = 0xdf;
	   WEI = 0;
	
	   DUAN = 1;
	   P0 = leddata[6];
	   DUAN = 0;

	   Delay50us();
	   WEI = 1;
	   P0 = 0xbf;
	   WEI = 0;
	
	   DUAN = 1;
	   P0 = leddata[7];
	   DUAN = 0;

	   Delay50us();
	   WEI = 1;
	   P0 = 0x7f;
	   WEI = 0;
	
	   DUAN = 1;
	   P0 = leddata[8];
	   DUAN = 0;
   }
}