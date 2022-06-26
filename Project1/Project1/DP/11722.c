#include <stdio.h>
#define MAX(a,b) (((a)>(b))? (a):(b))
int arr[1010]={0,};
int dp[1010]={1,};
int N;
int temp;
int dp_max;

void input()
{
	scanf("%d",&N);
	for (int i=1; i<N+1; i++)
	{
	scanf("%d", &arr[i]);
	dp[i]=1;
	}
	
//	for (int i=0; i<N+1; i++)
//	{
//		printf("%d ", dp[i]);
//	} 
}

int main()
{
	input();
	
	for (int i=1; i<N+1; i++)
	{
		for(int j=1; j<i; j++)
		{
			if (arr[j]>arr[i])
			{
				temp = dp[j]+1;
				dp[i]=MAX(temp,dp[i]);
			}
		}
	}
	
	for (int i=1; i<N+1; i++)
	{
		if (dp[i-1]<=dp[i])
		{
			dp_max=MAX(dp_max,dp[i]);
		}
	}
	
	printf("%d", dp_max);	
//	for (int i=1; i<N+1; i++)
//	{
//		printf("%d ", dp[i]);
//	}	

    return 0;
}
