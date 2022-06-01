#include <stdio.h>
#include <string.h>
#define SZ 1000001


int Arr[1001];
int T;
int n;
int solution(int num);


int main(void)
{
	scanf("%d",&T);
	int i;
	for (i=0;i<T;i++)
	{
		scanf("%d", &n);
		solution(n);
	}
}

int solution(int  num)
{
	Arr[0]=1;
	Arr[1]=1;
	int i;
	for (i=2;i<num+1;i++)
	{
		Arr[i]=(Arr[i-1]+Arr[i-2]+Arr[i-3]);
	}
	printf("%d\n",(Arr[num]));
	
	return 0;
}
