#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count[5]={}; // 카운팅 정렬 배열. 인덱스는 나열된 값이고 배열 내의 값은 개수가 됨. 

int main(void)
{
	int num=0;
	int arr[7]={1,3,2,4,5,1,1}; // 정렬 대상 요소 
	
	for (int i = 0; i<7; i++)
	{
		num=arr[i];
		count[num-1]++;
	}
	
	for (int i = 0; i<7; i++)
	{
		if (count[i]!=0) // 배열 내 값이 0 인 경우 개수가 0이라는 의미이므로 무시 
		{
			for (int j = 0; j<count[i]; j++)
			{
				printf("%d\n", i+1);
			}
		}
	}
	
	return 0;
}
