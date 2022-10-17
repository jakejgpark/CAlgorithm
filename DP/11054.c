#include <stdio.h>
#include <string.h>
#define MAX(a,b) (((a)>(b))? (a):(b))


int arr[1010];
int dp_ascend[1010];
int dp_descend[1010];
int n;
int dp_max=-1;

void input()
{
	scanf("%d",&n);
	arr[0]=dp_ascend[0]=dp_descend[0]=0;
	for (int i=1; i<n+1; i++)
	{
		scanf("%d",&arr[i]);
		dp_ascend[i]=dp_descend[i]=1;
	}
}


int main(void)
{
	input();
	int temp;
	
	for (int i=2; i<n+1; i++)
	{
		for(int j=i-1; j!=0; j--)
		{
			if (arr[j]<arr[i])
			{
				dp_ascend[i]=MAX(dp_ascend[j]+1,dp_ascend[i]);
			}
			else if (arr[j]>arr[i])
			{
				temp = MAX(dp_ascend[j],dp_descend[j]);
				dp_descend[i]=MAX(temp+1,dp_descend[i]);
			}
		}
	}
//	
//	for (int i=1; i<n+1; i++)
//	{
//		printf("%d ", dp_ascend[i]);
//	}
//	printf("\n");
//	for (int i=1; i<n+1; i++)
//	{
//		printf("%d ", dp_descend[i]);
//	}	
	
	for (int i=1; i<n+1; i++)
	{
		if (dp_max<dp_ascend[i])
		{
			dp_max=dp_ascend[i];
		}
		if (dp_max<dp_descend[i])
		{
			dp_max=dp_descend[i];
		}
	}
	printf("%d", dp_max);

	return 0;
	
}

