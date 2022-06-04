
#include <stdio.h>

int n;
int arr[1010]={0,};
	

int main(void)
{
	scanf("%d", &n);
	arr[0]=1;
	arr[1]=1;
	arr[2]=3;
	arr[3]=5;
	
	for (int i=4; i<n+1; i++)
	{
		arr[i]=(arr[i-1]%10007+2*arr[i-2]%10007);
	}
	
	printf("%d",arr[n]%10007);
}
