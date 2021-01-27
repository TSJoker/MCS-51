#include <reg52.h>
#include <intrins.h>
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
	int v = 0;
	beev = v;
	Delay100ms();
	beev = ~beev;
	Delay100ms();
}