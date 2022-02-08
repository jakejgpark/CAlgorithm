#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	char x[2001];
	fgets(x,sizeof(x),stdin);
	printf("%s", x);
}