#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
} coord;

int compare(const void* a, const void* b)
{
	coord A=*(coord*)a;
	coord B=*(coord*)b;
	
	if (A.x<B.x)
	{
		return -1;
	}
	else if (A.x==B.x)
	{
		if (A.y<B.y)
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 1;
	}
	return 0;
}

int main(void)
{
	int n;
	scanf("%d", &n);
	coord arr[n];

	int i=0;
	while (i<n)
	{
		scanf("%d %d", &arr[i].x, &arr[i].y);
		i++;
	}
	qsort(arr,n,sizeof(coord),compare);
	i=0;
	while (i<n)
	{
		printf("%d %d\n", arr[i].x, arr[i].y);
		i++;
	}
	
	return 0;
}

