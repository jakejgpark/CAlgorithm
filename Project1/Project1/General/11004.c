#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[5000010]={};
int N;
int K;

int compare(const void* a, const void* b)
{
	int A = *(int*)a;
	int B = *(int*)b;
	
	if (A<B)
		return -1;
	else if (A>B)
		return 1;
	return 0;
}
	

int main(void)
{
	scanf("%d %d", &N, &K);
	
	for (int i=0; i<N; i++)
	{
		scanf("%d",&arr[i]);
	}

	qsort(arr,N,sizeof(int),compare);
	printf("%d", arr[K-1]);

	return 0;
}
