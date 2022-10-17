#include <stdio.h>
#include <string.h>
#define MAX(a,b) (((a)>(b))? (a):(b))


int main(void)
{
	int T;
	int n;

	int result;
	
	scanf("%d", &T);
	for (int i=0; i<T; i++)
	{
		result = 0;
		n=0;
		scanf("%d", &n);
		int arr[2][100100]={0,};
		int dp[2][100100]={0,};
		for (int j=0; j<2; j++)
		{
			for (int k=1; k<n+1; k++)
			{
				scanf("%d",&arr[j][k]);
			}
		}
		dp[0][0]=arr[0][0]=0;
		dp[1][0]=arr[1][0]=0;
		
		dp[0][1]=arr[0][1];
		dp[1][1]=arr[1][1];
		
		for (int l=2; l<n+1; l++)
		{
			{
				dp[0][l]=MAX(dp[1][l-2]+arr[0][l],dp[1][l-1]+arr[0][l]);
				dp[1][l]=MAX(dp[0][l-2]+arr[1][l],dp[0][l-1]+arr[1][l]);

			}
		}
		
//		for (int i=0; i<2; i++)
//		{
//			for (int j=0; j<n+1; j++)
//			{
//				printf("%d ", dp[i][j]);
//			}
//			printf("\n");
//		}
		result = MAX(dp[0][n],dp[1][n]);
		printf("%d\n",result);
		
		
	}
	return 0;
}

//
//		for (int i=0; i<2; i++)
//		{
//			for (int j=0; j<n+1; j++)
//			{
//				printf("%d ", arr[i][j]);
//			}
//			printf("\n");
//		}


