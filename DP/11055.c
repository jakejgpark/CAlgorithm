#include <stdio.h>
#include <string.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int n;
int arr[1010]={};
int dp[1010]={};

void input()
{

	scanf("%d", &n);
	
	dp[0]=arr[0]=0;
	for (int i=1; i<n+1; i++)
	{
		scanf("%d",&arr[i]);
	}	
	for (int i=1; i<n+1; i++)
	{
		dp[i]=arr[i];
	}
}

void solution()
{
	int temp;
	for (int i=2; i<n+1; i++)
	{
		for (int j=1; j<i; j++)
		{
			if (arr[i]>arr[j])
			{
				temp=dp[j]+arr[i];
				dp[i]=MAX(dp[i],temp);
			}
		}
	}
}

int main(void)
{
	input();
	solution();
	int dpmax=-1;
	for (int i=0; i<n+1; i++)
	{
		if (dp[i]>=dpmax)
		{
			dpmax=dp[i];
		}
	}
	
	printf("%d", dpmax);
//	
//	printf("arr");
//	for (int i=0; i<n+1; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	printf("dp");
//	for (int j=0; j<n+1; j++)
//	{
//		printf("%d ", dp[j]);
//	}
//	printf("\n");
	
	return 0;
}


