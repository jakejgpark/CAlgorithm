#include <stdio.h>
#pragma warning(disable:4996)
int main()
{
	int y,m,d;
	scanf("%d.%d.%d", &y,&m,&d);
	printf("%02d.%02d.%02d", y,m,d);
}