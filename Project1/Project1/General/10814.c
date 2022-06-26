#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int age;
	int index;
	char name[200];
} person;

int compare (const void* a, const void* b)
{
	person A=*(person*)a;
	person B=*(person*)b;
	
	if (A.age<B.age)
	{
		return -1;
	}
	else if (A.age>B.age)
	{
		return 1;
	}
	else
	{
		if (A.index<B.index)
		{
			return -1;
		}
		else
		{
			return 1;
		}
	return 0;
}
}

int main()
{
	int n;
	scanf("%d", &n);
	person p[n];
	int i=0;
	while (i<n)
	{
		scanf("%d %s", &p[i].age, p[i].name);
		p[i].index=i;
		i++;
	}
	i=0;
	
	qsort(p,n,sizeof(person),compare);
	
	while (i<n)
	{
		printf("%d %s\n", p[i].age, p[i].name);
		i++;
	}

    return 0;
}
