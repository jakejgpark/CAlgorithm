#include <stdio.h>
#include <string.h>


int main()
{
	int i;
	int j;
	int k;
	int num;
	scanf("%d",&num);
	
	for (i=0; i<num;i++)
	{
		for (k=0; k<i;k++)
			printf(" ");
		
		for (j=2*(num-i-1)+1; j!=0; j--)
			printf("*");
		printf("\n");
	}
	
	for (i=0; i<num-1;i++)
	{
		for (k=num-i-2; k!=0; k--)
			printf(" ");
		
		for (j=0; j<2*(i+1)+1; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
	

