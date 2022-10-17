#include <stdio.h>
#include <string.h>

int n;
int k;
int dp[201][201]={0,};

void input()
{
	scanf("%d",&n);
	scanf("%d",&k);
	
	for (int i=0; i<n+1; i++)
	{
		dp[i][1]=1;
	}
}

int main(void)
{
	input();

	for (int i=3; i<n+1; i++)
	{
		dp[n][k]+=dp[i][k-1];
	}
	
	return 0;
}

