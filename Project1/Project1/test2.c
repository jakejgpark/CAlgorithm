#include <stdio.h>

int main(void)
{
	int num1 = 1;
	int num2 = 1;
	while (num1 < 10)
	{
		num2 = 1;
		while (num2 < 10)
		{
			printf("%dx%d=%d \n", num1, num2, num1 * num2);
			num2++;
		}
		num1++;
	}
	return 0;
}