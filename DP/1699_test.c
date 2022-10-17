#include <stdio.h>
#include <string.h>
#define MIN(a,b) (((a)<(b))? (a):(b))

int n=0;
int cnt=0;
int dp[100100]={0,};

void input()
{
	scanf("%d",&n);
}

int main(void)
{
	input();

	for(int i=1; i<n+1; i++)
	{
		dp[i]=i;
		for (int j=1; j*j<i+1; j++)
		{
			dp[i]=MIN(dp[i],dp[i-j*j]+1);
		}
	}
	printf("%d", dp[n]);
	
	return 0;
}

