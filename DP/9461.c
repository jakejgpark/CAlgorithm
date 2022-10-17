#include <stdio.h>
#include <string.h>

long long dp[110]={0};
int n;
int T;

void input()
{
	scanf("%d",&n);
}

int main(void)
{
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	dp[4]=2;
	dp[5]=2;
	scanf("%d",&T);
	for(int i=0; i<T; i++)
	{
		input();
		for (int j=6; j<n+1; j++)
		{
			dp[j]=dp[j-1]+dp[j-5];
//			printf("here j %lld: %lld\n",j,dp[j]);
		}
		printf("%llu\n",dp[n]);
	}
	
	return 0;
}

