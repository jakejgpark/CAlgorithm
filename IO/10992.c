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
		
		if (i==0)
		{
			printf("*\n");
		}
		else if (i==num-1)
		{
			for (i=0; i<2*num-1; i++)
				printf("*");
		}
		else
		{
			for (j=0;j<2*(i+1);j++)
			{
				if (j==0||j==2*(i+1)-2)
					printf("*");
				else
					printf(" ");
			}
		printf("\n");
	}
	}
	return 0;
}
	

