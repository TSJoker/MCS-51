#include <reg52.h>
#include <intrins.h>

#define unchar unsigned char

sbit WEI = P2^7;//由原理图知位选在P2-7口
sbit DUAN = P2^6;//由原理图定义段选
unchar keynum = 22;


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
void buttonscan()
{
	P3 = 0xf0;
	if (P3 != 0xf0)
	{
	Delay50us();
	if (P3 != 0xf0)
	{
		switch (P3)
		{
			case 0xe0 :keynum = 0; break;
			case 0xd0 :keynum = 1; break;
			case 0xb0 :keynum = 2; break;
			case 0x70 :keynum = 3; break;
		}
	
	P3 = 0x0f;
		switch (P3)
		{
			case 0x0e :keynum = keynum; break;
			case 0x0d :keynum = keynum + 4; break;
			case 0x0b :keynum = keynum + 8; break;
			case 0x07 :keynum = keynum + 12; break;
		}
		 while (P3 != 0x0f);
	  	}
	}
	P3 = 0xff;
	if  (P3 != 0xff)
	{
	Delay50us();
	if  (P3 != 0xff)
	{
		switch (P3)
		{
			case 0xfe :keynum = 16; break;
			case 0xfd :keynum = 17; break;
			case 0xfb :keynum = 18; break;
			case 0xf7 :keynum = 19; break;
		}
		while (P3 != 0xff);
	}
	}	
}
	

void main()
{
	WEI = 1;
	P0 = 0xfe;
	WEI = 0;

	DUAN = 1;
	while(1)
	{
		buttonscan();
		P0 = leddata[keynum];
	}

}