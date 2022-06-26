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
<<<<<<< HEAD
=======
	arr[0]=dp[0]=1;
>>>>>>> c549d4224518a28487d2b1864bec2ec47006f63b
	for (int i=1; i<N+1; i++)
	{
	scanf("%d", &arr[i]);
	dp[i]=1;
	}
	
//	for (int i=0; i<N+1; i++)
//	{
//		printf("%d ", dp[i]);
<<<<<<< HEAD
//	} 
=======
//	}
>>>>>>> c549d4224518a28487d2b1864bec2ec47006f63b
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
<<<<<<< HEAD
		if (dp[i-1]<=dp[i])
		{
			dp_max=MAX(dp_max,dp[i]);
		}
	}
	
	printf("%d", dp_max);	
=======
		if (dp[i-1]<dp[i])
		{
			dp_max=dp[i];
		}
	}
	
	printf("%d\n", dp_max);	
>>>>>>> c549d4224518a28487d2b1864bec2ec47006f63b
//	for (int i=1; i<N+1; i++)
//	{
//		printf("%d ", dp[i]);
//	}	

    return 0;
}
