#include <reg52.h>
#include <intrins.h>//循环移位操作头文件

#define unchar unsigned char
#define unint unsigned int//宏定义，定义unsigned int为unint,上同
unchar L1;//输入一个变量L1

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
}//100ms延时函数，从stc-isp软件上复制得

void main()
{
	L1 = 0xfe;//给L1赋值为1 1 1 1 1 1 1 0
	P1 = L1;//将L1的值赋给P1口，使得只有P1_0为0，LED1亮
	Delay100ms();//延时
	while(1)
	{
		L1 = _crol_(L1,1);//对L1实现循环左移的操作
		P1 = L1;//将值赋给P1
		Delay100ms();//延时	
	}
}
//实现了流水灯操作
