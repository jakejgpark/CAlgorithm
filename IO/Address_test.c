#include <stdio.h>


int a=1;
int b;
int* c=&a;
int port;
int main(void)
{
	for (int i=0; i<40; i++)
	{
		scanf("%d", &port);
		printf("P00_IN �ּҰ�: %p\n", c);	
		printf("port 0x100/4 ���: %x (hex)\n",port*0x100/4);
		printf("Reg32 ����(/4 ������):  %p\n", c+(port*0x100));
		printf("Reg32 ����(/4 ����):    %p\n", c+(port*0x100/4));
	}
	return 0;
}
