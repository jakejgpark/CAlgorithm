#include <stdio.h>
#pragma warning(disable:4996)

void output(int count)
{
		printf("hi");
		return;         //���� ���ǵ��� ����.
}


int main(void)
{
	output(3);
	return 0;
}