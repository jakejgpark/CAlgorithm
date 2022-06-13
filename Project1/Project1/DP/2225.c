#include <stdio.h>
#include <string.h>
#define Modular 1000000000

int N;
int K;
int dp[201][201]={0,};


void input()
{
	scanf("%d",&N);
	scanf("%d",&K);
	
	for (int i=0; i<N+1; i++)
	{
		dp[1][i]=1; // ¾Õ ÀÎµ¦½º: °³¼ö, µÞ ÀÎµ¦½º: °ª// 
	}
}

int main(void)
{
	input();
	
	for (int i=2; i<K+1; i++)
	{
		
	
	return 0;
}

