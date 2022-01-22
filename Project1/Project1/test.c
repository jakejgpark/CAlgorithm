#include <stdio.h>
#pragma warning(disable:4996)


int main(void)
{
	int numArr[10] = { 11,22,33,44,55,66,77,88,99,0 };
	printf("%d", sizeof(numArr));
	printf("%d", sizeof(numArr)/sizeof(int));
	return 0;
}