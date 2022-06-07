#include <stdio.h>
#include <string.h>
#define MAX(a,b) (((a)>(b))? (a):(b))


int main(void)
{
	int arr[10001]={0,};
	int dp[10001]={0,};
	int temp;
	int n;
	scanf("%d",&n);
	
	for (int i=1; i<n+1; i++)
	{
		scanf("%d",&arr[i]);
	}

//	for (int i=0; i<n; i++)
//	{
//		printf("%d ",arr[i]);
//	}
	
	dp[0]=arr[0]=0;
	dp[1]=arr[1];
	dp[2]=dp[1]+arr[2];
	
	for (int j=3; j<n+1; j++)
	{
		temp=MAX(arr[j]+dp[j-2],arr[j]+arr[j-1]+dp[j-3]);
		dp[j]=MAX(dp[j-1],temp);
	}
	
	printf("%d\n",dp[n]);
	
	
	printf("arr:");
	for (int i=0; i<n+1; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	printf("dp:");
	for (int i=0; i<n+1; i++)
	{
		printf("%d ",dp[i]);
	}

	return 0;
}

