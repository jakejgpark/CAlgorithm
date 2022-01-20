#include <stdio.h>
#pragma warning(disable:4996)

void output(int count)
{
		printf("hi");
		return;         //값이 정의되지 않음.
}


int main(void)
{
	output(3);
	return 0;
}