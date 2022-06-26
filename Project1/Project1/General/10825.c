#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int language;
	int enligsh;
	int math;
	char name[20];
} info;

int compare(const void* a, const void* b)
{
	info A = *(info*)a;
	info B = *(info*)b;
	
	if (A.language < B.language)
	{
		return 1;
	}
	else if (A.language > B.language)
	{
		return -1;
	}
	else
	{
		if (A.enligsh < B.enligsh)
		{
			return -1;
		}
		else if (A.enligsh > B.enligsh)
		{
			return 1;
		}
		else
		{
			if (A.math < B.math)
			{
				return 1;
			}
			else if (A.math > B.math)
			{
				return -1;
			}
			else
			{
				return -strcmp(B.name, A.name);
			}
		}
	}
	return 0;
}
	

int main()
{
	info p[1000];
	int n;
	scanf("%d", &n);
	int i = 0;
	while (i<n)
	{
		scanf("%s %d %d %d", p[i].name, &p[i].language, &p[i].enligsh, &p[i].math);
		i++;
	}
	i = 0;
	qsort(p,n,sizeof(info),compare);
	
	while (i<n)
	{
		printf("%s\n", p[i].name);
		i++;
	}


    return 0;
}
