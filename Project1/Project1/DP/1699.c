#include <stdio.h>
#include <string.h>

int n=0;
int cnt=0;
int dp[100100]={0,};

void input()
{
	scanf("%d",&n);
}

int main(void)
{
	input();

	while (n!=0)
	{
		for(int i=n; i>0; i--)
		{
			if (n-i*i<0)
			{
//				printf("i %d\n", i);
//				printf("minus n: %d\n", n);
//				printf("count %d\n", cnt);
				continue;
			}
			else if (n-i*i>0)
			{
				n=n-i*i;
				cnt++;
//				printf("i %d\n", i);
//				printf("plus n: %d\n", n);
//				printf("count %d\n", cnt);
				break;
			}
			else if (n-i*i==0)
			{
				n=n-i*i;
				cnt++;
//				printf("i %d\n", i);
//				printf("zero n: %d\n", n);
//				printf("count %d\n", cnt);
				break;
			}
		}
	}
	printf("%d", cnt);
	
	return 0;
}

