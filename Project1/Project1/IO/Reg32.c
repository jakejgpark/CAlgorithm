#include <stdio.h>

int a=1;
int b;
int* c=&a;
int port;
int arr[32]={1,2,3,};
int main(void)
{
	int* ptr;
	ptr = arr;
	printf("%p", arr);
	return 0;
}
