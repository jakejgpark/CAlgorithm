#include <stdio.h>
#include <string.h>


int main()
{
	int i;
	int j;
	int k;
	int l;
	int num;
	scanf("%d",&num);
	
	for(i=0; i<num; i++)
	{
		for (k=num-i-1;k!=0;k--)
			printf(" ");
		for (j=0; j<=i; j++)
			printf("*");
		printf("\n");
	}
		
	for(i=0; i<num-1; i++)
	{
		for (j=0; j<=i; j++)
			printf(" ");
		
		for (k=num-i-1; k!=0; k--)
			printf("*");
		
		printf("\n");
	}
	
	return 0;
}
	

