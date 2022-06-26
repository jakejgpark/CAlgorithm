#include <stdio.h>

typedef struct {
	int x;
	int y;
} coord;

int compare(const void* a, const void* b)
{
	coord A = *(coord*)a;
	coord B = *(coord*)b;
	
	if (A.y<B.y)
	{
		return -1;
	}
	else if (A.y==B.y)
	{
		if (A.x<B.x)
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

int main()
{
	int n;
	scanf("%d", &n);
	coord p[n];
	
	int i=0;
	
	while (i<n)
	{
		scanf("%d %d", &p[i].x, &p[i].y);
		i++;
	}
	
	qsort(p,n,sizeof(coord),compare);
	i=0;
		
	while (i<n)
	{
		printf("%d %d\n", p[i].x, p[i].y);
		i++;
	}

    return 0;
}
