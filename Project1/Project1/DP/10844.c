#include <stdio.h>
#include <string.h>
#define mod 100007


void solution(int num);

int main(void)
{
	int n;
	scanf("%d",&n);
	int arr[1001][10]={0,};
	int sum=0;
	
	for (int i = 0; i<10; i++)
	{
		arr[1][i]=1;
	}
	
	for (int i = 2; i<n+1; i++)
	{
		for (int j = 0; j<10; j++)
		{
			for (int k = j; k<10; k++)
			{
				arr[i][j]+=arr[i-1][k]%mod;
			}
		}
	}
	
	for (int i = 0; i<10; i++)
	{
		sum = sum%mod+arr[n][i]%mod;
	}
	printf("%d",sum);
	return 0;
}

