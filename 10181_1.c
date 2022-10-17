#include <stdio.h>
#pragma warning(disable:4996)
int main(void)
{
	int N;
	int max = -1000001, min = 1000001;
	int num;
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		if (num < min)
		{
			min = num;
		}
		if (num > max)
		{
			max = num;
		}
	}
	printf("%d %d", min, max);
	return 0;
}