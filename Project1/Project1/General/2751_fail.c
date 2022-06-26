#include <stdio.h>
#include <string.h>
#include <time.h>

int T;
int temp;
int main(void)
{
	clock_t start = clock();
	
	scanf("%d", &T);
	int arr[T];
	
	for (int i=0; i<T; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	while (1)
	{
		int cnt=0;
		for (int i=0; i<T; i++)
		{
			if ((i>0)&&(arr[i]<arr[i-1]))
			{
				temp=arr[i-1];
				arr[i-1]=arr[i];
				arr[i]=temp;
				cnt++;
			}
		}
		if (cnt==0)
		{
			break;
		}
	}
	
	for (int i=0; i<T; i++)
	{
		printf("%d\n",arr[i]);
	}
	
	clock_t end = clock();
	printf("time elapsed: %lf\n", (double)(end-start)/CLOCKS_PER_SEC); 
	
	return 0;
}

