#include <stdio.h>
#include <string.h>


int main()
{
	int i;
	int j;
	int k;
	
	int num;
	scanf("%d",&num);
	
	for (i=0; i<num; i++)
	{
		for (j=num-i-1;j!=0;j--)
			printf(" ");
		for (k=0; k<i+1; k++)
				printf("* ");
		printf("\n");
	}
	return 0;
}
	

