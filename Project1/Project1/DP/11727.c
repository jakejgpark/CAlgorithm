#include <stdio.h>
#include <string.h>
#define SZ 1000001


int Arr[1001];
int n;
int solution(int num);


int main(void)
{
	scanf("%d", &n);
	solution(n);
	return 0;
}

int solution(int num)
{
	Arr[0]=Arr[1]=1;
	int i;
	for (i=2;i<num+1;i++)
	{
		Arr[i]=(Arr[i-1]+2*Arr[i-2])%10007;
	}
	printf("%d",(Arr[num]));
	
	return 0;
}
