#include <reg52.h>
unsigned int  i; //����һ���޷������ͱ���iȡֵ��Χ��0~65535
void main()	//void����������ѭ��
{
	i = 60000;//��i��һ�����ʵ�ֵ��ֵԽС��˸Խ��
	while (i--)//ѭ��ִ��60000�Ρ���һ����ʱ������
	P1 = 0xaa;//0xaa��ʾ1 0 1 0 1 0 1 0���ֱ��ӦP1_7-P1_0,����LED1,3,5,7�����������
	i = 60000;
	while (i--)
	P1 = 0x55;//0x55��ʾ0 1 0 1 0 1 0 1������LED2,4,6,8�����������
}
//����������ʵ��LED�ƵĽ�����˸