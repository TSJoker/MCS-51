#include <reg52.h>
sbit LED2=P1^1;//定义单片机P1^1口，对应的是LED灯2
sbit LED7=P1^6;//定义单片机P1^6口，对应的是LED灯7
void main()
{
 	LED2=0;//LED为低电平，即值为0时亮起	
	LED7=0;//同理，使LED6亮起
}
//根据单片机原理图可知，P1_0口-P1_7分别对应LED灯0-8，指定某个口为低电平即对应的LED灯亮。
