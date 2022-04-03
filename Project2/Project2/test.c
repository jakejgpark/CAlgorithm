#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int num1 = 100;
	int* ptr;

	ptr = &num1;
	printf("0x%p\n", num1);
	printf("%d", *ptr);

	return 0;
}