#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int main(void)
{
	char input[10] = "He";
	char result[5] = "Love";
	strcpy(result, input);
	printf("%s", result);
	return 0;
}