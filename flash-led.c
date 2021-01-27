#include <reg52.h>
#include <intrins.h>

#define unchar unsigned char
#define unint unsigned int
unchar L1;

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
	L1 = 0xfe;
	P1 = L1;
	Delay100ms();
	while(1)
	{
		L1 = _crol_(L1,1);
		P1 = L1;
		Delay100ms();	
	}
}
