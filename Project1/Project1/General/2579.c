#include <stdio.h>
#include <string.h>
#define MAX(a,b) (((a)>(b))? (a):(b))

int n;
int arr[310]={0,};
int dp[310]={0,};

void input()
{
	scanf("%d", &n);
	arr[0]=dp[0]=0;
	for (int i=1; i<n+1; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	dp[1]=arr[1];
	dp[2]=dp[1]+arr[2];
}

int main(void)
{
	int temp=0;
	input();	
	
	for (int i=3; i<n+1; i++)
	{
		if (i==3 && i==n)
		{
			dp[i]=MAX(arr[1]+arr[3],arr[2]+arr[3]);	
		}
		else if (i==3)
		{
			dp[i]=MAX(arr[1]+arr[2],arr[1]+arr[3]);
			dp[i]=MAX(dp[i],arr[2]+arr[3]);	
		}
		else if (i==n)
		{
			dp[i]=MAX(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i]);
		}
		else
		{
			temp=MAX(dp[i-3]+arr[i-1]+arr[i],dp[i-2]+arr[i]);
			dp[i]=MAX(temp,dp[i-2]+arr[i-1]);
		}
	}
	
	for (int i=1; i<n+1; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	for (int i=1; i<n+1; i++)
	{
		printf("%d ", dp[i]);
	}
	
	printf("%d",dp[n]);
	return 0;
}

