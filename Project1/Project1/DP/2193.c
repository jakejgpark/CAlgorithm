#include <stdio.h>

int n;
long long arr[100]={0,};
int sum;

int main(void)
{
	scanf("%d", &n);
	
	arr[0]=0;
	arr[1]=1;
	arr[2]=1;
	for(int i=3; i<n+1; i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
	}
	
	printf("%d", arr[n]);
return 0;
}

