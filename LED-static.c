#include <reg52.h>

sbit WEI = P2^7;//由原理图知位选在P2-7口
sbit DUAN = P2^6;//由原理图定义段选

void main()
{
   WEI = 1;//位选锁存器开
   P0 = 0xfe;//选择第一位数码管
   WEI = 0;//关闭位选锁存器
   DUAN = 1;//打开段选锁存器
   P0 = 0x06;//0000 0110代表数码管显示数字1
   DUAN = 0;//关闭段选锁存器
}