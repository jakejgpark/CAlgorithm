#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxvalue 10001

int count[maxvalue]={}; // �迭�� �Լ� �ۿ��� ������  


int main(void)
{
	int N=0;
	int num=0;
	scanf("%d", &N);
	
	for (int i = 0; i<N; i++)
	{
		scanf("%d",&num);
		count[num]++;
	}
	
	for (int i = 1; i<maxvalue+1; i++)
	{
		if (count[i]!=0)
		{
			for (int j = 0; j<count[i]; j++)
			{
				printf("%d\n", i);
			}
		}
	}
	
	return 0;
}
