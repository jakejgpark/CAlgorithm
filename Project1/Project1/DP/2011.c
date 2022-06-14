#include <stdio.h>
#include <string.h>    // strcpy 함수가 선언된 헤더 파일
#define MAX(a,b) (((a)>(b))? (a):(b))

int main()
{
	char* p;
	char s[5001];
	int len, temp;
	int dp[5001];
	
	scanf("%s", s+1);
	
	if(*(s+1)=='0')
	{
		printf("0\n");
		return 0;
	}
	
	
	
    return 0;
}
