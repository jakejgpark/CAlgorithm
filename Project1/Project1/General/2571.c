#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int compare(const void* a, const void* b)
{
	int num1=*(int*)a;
	int num2=*(int*)b;
	
	if (num1<num2)
	{
		return -1;
	}
	if (num1>num2)
	{
		return 1;
	}
	return 0;
}

int main(void)
{
	int arr[1000100]={};
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	qsort(arr,n,sizeof(int),compare);
	
	for(int i=0; i<n; i++)
	{
		printf("%d\n",arr[i]);
	}

	return 0;
}

