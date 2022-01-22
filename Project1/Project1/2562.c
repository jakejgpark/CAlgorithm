#include <stdio.h>
#pragma warning(disable:4996)


int main(void)
{
	int max = 0;
	int i;
	int index=0;
	int array[9]; // array ¼±¾ð

	for (i = 0; i < 9; i++)
	{
		scanf("%d", &array[i]);
		if (max < array[i])
		{
			max = array[i];
			index= i+1;
		}
	}
	printf("%d\n%d", max,index);
	return 0;
}