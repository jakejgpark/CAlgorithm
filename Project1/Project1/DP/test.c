#include <stdio.h>


int a=1;
int b;
int* c=&a;
int port;
int main(void)
{
	for (int i=0; i<40; i++)
	{
		scanf("Port: %d", &port);
		printf("P00_IN 주소값: %p\n", c);	
		printf("port 0x100/4 계산: %x\n",port*0x100/4);
		printf("Reg32 최종: %p\n", c+(port*0x100/4));
	}
}
