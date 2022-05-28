#include <stdio.h>

int arr[1001];
int num;
void solution(int n);

int main(void)
{
	scanf("%d",&num);
	solution(num);
}


void solution(int n)
{
	int i;
	arr[0]=0;
	arr[1]=1;
	arr[2]=2;
	for(i=3;i<n+1;i++)
	{
		arr[i]=arr[i-1]+arr[i-2];
	}
	printf("%d",arr[n]);
}

	
