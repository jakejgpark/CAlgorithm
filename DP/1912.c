#include <stdio.h>
#include <string.h>
#define MAX(a,b) (((a)>(b))? (a):(b))


int n;
int arr[100010];
int dp[100010];
int dp_max=-1001;

void input()
{
	scanf("%d",&n);
	
	for (int i=1; i<n+1; i++)
	{
		scanf("%d",&arr[i]);
		dp[i]=arr[i];
	}
}


int main(void)
{
	input();
	
	
	for (int i=2; i<n+1; i++)
	{
		dp[i]=MAX(dp[i],dp[i-1]+arr[i]);
	}
//	
//	for(int i=1; i<n+1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	
//	printf("\n");
//	for(int i=1; i<n+1; i++)
//	{
//		printf("%d ", dp[i]);
//	}
//
	for(int i=1; i<n+1; i++)
	{
		if (dp_max<dp[i])
		{
			dp_max=dp[i];
		}
	}
//	printf("\n");
//	
	printf("%d", dp_max);
	return 0;
}

