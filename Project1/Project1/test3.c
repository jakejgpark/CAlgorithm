#include <stdio.h>
#pragma warning(disable:4996)

int compare_abs(int num1, int num2);
int get_abs(int num);


int main(void)
{
	int num1, num2;
	printf("두 개의 정수 입력:");
	scanf("%d %d", &num1, &num2);
	printf("%d와 %d중 절대값이 큰 정수: %d \n", num1, num2, compare_abs(num1, num2));
	return 0;
}

int compare_abs(int num1, int num2)
{
	if (get_abs(num1) > get_abs(num2))
		return num1;
	else
		return num2;
}

int get_abs(int num)
{
	if (num < 0)
		return num * (-1);
	else
		return num;
}