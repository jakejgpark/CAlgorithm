#include <stdio.h>

int n;
int arr[1010][10]={0,};
int sum;

int main(void)
{
	scanf("%d",&n);
	
	for (int i=0; i<10; i++)
	{
		arr[1][i]=1;
	}
	
	for (int i=2; i<n+1; i++)
	{
		for (int j=0; j<10; j++)
		{
			for (int k=0; k<j+1; k++)
			{
				arr[i][j] += arr[i-1][k]%10007;
			}
		}
	}
	
	for(int i=0; i<10; i++)
	{
		sum+=arr[n][i]%10007;
	}
	
	printf("%d",sum%10007);
	

	return 0;
}

