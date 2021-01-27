#include <reg52.h>
#include <intrins.h>//延时函数需要的头文件
sbit beev = P2^3;//由原理图可知蜂鸣器模块与单片机P2_3口相连
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
	int v = 0;//由原理图可知蜂鸣器在低电平工作，所以定义一个变量赋值为0
	beev = v;//将这个值赋值给beev，蜂鸣器响
	Delay100ms();//蜂鸣器响的时间为100毫秒
	beev = ~beev;//将beev的值取反，蜂鸣器不响
	Delay100ms();//不响的时间为100ms
}
