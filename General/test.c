#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count[5]={}; // ī���� ���� �迭. �ε����� ������ ���̰� �迭 ���� ���� ������ ��. 

int main(void)
{
	int num=0;
	int arr[7]={1,3,2,4,5,1,1}; // ���� ��� ��� 
	
	for (int i = 0; i<7; i++)
	{
		num=arr[i];
		count[num-1]++;
	}
	
	for (int i = 0; i<7; i++)
	{
		if (count[i]!=0) // �迭 �� ���� 0 �� ��� ������ 0�̶�� �ǹ��̹Ƿ� ���� 
		{
			for (int j = 0; j<count[i]; j++)
			{
				printf("%d\n", i+1);
			}
		}
	}
	
	return 0;
}
