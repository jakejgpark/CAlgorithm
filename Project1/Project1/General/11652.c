#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(void)
{
	int N;
	long long arr[100010];

	
	scanf("%d",&N);
	
	int compare(const void* a, const void* b)
	{
		long long* A = (long long*)a;
		long long* B = (long long*)b;
		
		if (*A>*B)
			return 1;
		else if (*A<*B)
			return -1;
		return 0;
	}
		
	for (int i=0; i<N; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	qsort(arr,N,sizeof(long long), compare);
	
	int cnt=0;
	int max_cnt=0;
	int ans=arr[0];
	
	for (int i=0; i<N; i++)
	{
		printf("here %d ", arr[i]);
	}
	
	for (int i=1; i<N; i++)
	{
		if (arr[i-1]==arr[i])
		{
			cnt++;
		}
		else
		{
			cnt=0;
		}
		
		if (cnt>max_cnt)
		{
			max_cnt=cnt;
			ans=arr[i];
		}
	}
	
	printf("%d", ans);

	return 0;
}
