#include <stdio.h>
#include <string.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int _max(int a, int b)
{
	if (a>b)
	{
		return a;}
	else
	{
		return b;}
}

int main(void)
{
	int T, n;
	int arr[2][100001]={0,};
	int max=0;
	scanf("%d",&T);
	scanf("%d",&n);
	
	
	
	/* arr ¿Ï¼º */ 
	for (int i=0;i<T;i++)
	{
		for (int j=0; j<2; j++)
		{
			for(int k=1; k<n+1; k++)
			{
				scanf("%d",&arr[j][k]);
			}
		}
		arr[0][0]=arr[1][0]=0;
		
		for (int j=2; j<n+1; j++)
		{
			for(int k=0; k<2; k++)
			{
				if (k==0)
				{
					arr[k][j]=arr[k][j]+_max(arr[1][j-1],arr[1][j-2]);
					if (arr[k][j]>max)
						max=arr[k][j];
				}
				else
				{
					arr[k][j]=arr[k][j]+_max(arr[0][j-1],arr[0][j-2]);
					if (arr[k][j]>max)
						max=arr[k][j];
				}
			}
		}
		printf("%d\n",max);
	}
	
	return 0;
}


