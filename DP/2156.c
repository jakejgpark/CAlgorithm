#include <stdio.h>
#include <string.h>
#define MAX(a,b) (((a)>(b))? (a):(b))


int main(void)
{
	int t,n;
	int ans;
	int dp[2][100001]={0,};
	int arr[2][100001]={0,};
	
	scanf("%d", &t);
	
	while (t--)
	{
		scanf("%d",&n);
		
		for(int i=0; i<2; i++)
		{
			for(int j=1; j<n+1; j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		
		dp[0][0]=dp[1][0]=0;
		dp[0][1]=arr[0][1];
		dp[1][1]=arr[1][1];
		
		for (int i=0; i<n+1; i++)
		{
			dp[0][i]=MAX(dp[1][i-1],dp[1][i-1])+arr[0][i];
			dp[1][i]=MAX(dp[0][i-1],dp[0][i-2])+arr[1][i];
		}
	}
	printf("%d",MAX(dp[0][n],dp[1][n]));
	
	
	return 0;
}


