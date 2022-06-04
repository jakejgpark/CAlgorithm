#include <stdio.h>

int n;
int arr[101][10]={0,};
int sum;	

int main(void)
{
	scanf("%d",&n);
	for (int i=1; i<10; i++)
	{
		arr[1][i]=1;
	}
	arr[1][0]=0;
	
	for (int i=2; i<n+1; i++)
	{
		for(int j=0; j<10; j++) // ÀÚ¸®¼ö 
		{
			if (j==0)
			{
				arr[i][j]=arr[i-1][1];
			}
			else if (j==9)
			{
				arr[i][j]=arr[i-1][8];
			}
			else
			{
				arr[i][j]=arr[i-1][j-1]%1000000000+arr[i-1][j+1]%1000000000;
				if (arr[i][j]<0)
				{
					printf("overflow");
				}
			}
		}
	}
	
	for (int i=0; i<10; i++)
	{
		sum=sum%1000000000+arr[n][i]%1000000000;
	}
	printf("%d",sum%1000000000);
}

