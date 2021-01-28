#include <reg52.h>
#include <intrins.h>
#define unchar unsigned char
#define unint unsigned int
sbit WEI = P2^7;//由原理图知位选在P2-7口
sbit DUAN = P2^6;//由原理图定义段选

unchar leddata[] = //定义一个数组用来存储需要显示的数据
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
	0x00,  //"熄灭"
};
void Delay100ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 5;
	j = 52;
	k = 195;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main()
{
	unint i = 0;//定义一个无符号变量i
	WEI = 1;//打开位选锁存器
	P0 = 0x00;//选择所有数码管
	WEI = 0;//锁存位选数据
	while (1)
	{
		DUAN = 1;//打开段选锁存器
		P0 = leddata[i];//将数组中的值按位赋给P0
		DUAN = 0;//锁存段选数据
		Delay100ms();//延时100ms
		i++;//按位使数组中元素赋值给P0
		if (i == 10)//判断是否已经显示过十个元素
		{
		i = 0;//将i清零再循环
		}
		
	
	}
	


}
