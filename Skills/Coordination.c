#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}coord;


int main()
{
	coord A;
	coord B;
	A.x=1;
	A.y=2;
	B.x=3;
	B.y=4;
	coord* ptr=&A;
	
	printf("%d",ptr->x);
	
	return 0;
}
