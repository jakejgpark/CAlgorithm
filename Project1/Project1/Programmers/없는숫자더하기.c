#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int arr[]={1,2,3};

int solution(int numbers[], size_t numbers_len) {
	int answer=45;
	for(int i = 0; i<sizeof(arr)/sizeof(int); i++)
	{
		answer-=numbers[i];
	}
	
    return answer;
}

int main()
{
	printf("%d",solution(arr, sizeof(arr)/sizeof(int)));
	
	return 0;
}

