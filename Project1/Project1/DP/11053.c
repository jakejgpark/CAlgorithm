#include <stdio.h>
#include <string.h>
#define MAX(a,b) (((a)>(b))? (a):(b))


int main(void)
{
	int n;
	scanf("%d",&n);
	int arr[1010]={0,};
	int dp[1010]={1,1,0,};
	int dp_max=1;
	
	for (int i=0; i<n+1; i++)
	{
		dp[i]=1;
	}
	
	for (int i=1; i<n+1; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	for (int i=2; i<n+1; i++)
	{
		if (i==2 && (arr[i]>arr[i-1]))
		{
			dp[i]=2;
		}
		else
		{
			for (int j = 1; j<i; j++)
			{
				if (arr[i]>arr[j])
				{
					dp[i]=MAX(dp[i],dp[j]+1);
				}
			}
		}
	}
	
	for (int i=1; i<n+1; i++)
	{
		printf("%d ",dp[i]);
	}
	
//	for (int i=2; i<n+1; i++)
//	{
//		if (dp[i]>=dp[i-1])
//		{
//			dp_max=MAX(dp_max,dp[i]);
//		}
//	}
//	
//	printf("%d",dp_max);
	
	

	return 0;
}

