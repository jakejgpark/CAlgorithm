#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int count_zero=0;
    int count=0;
    int max=0;
    int min=0;
    int min_rank=0;
    int max_rank=0;
    
    for (int i=0; i<lottos_len; i++)
    {
    	if (lottos[i]==0)
    	{
    		count_zero++;
    	}
    }
    
    for (int i=0; i<lottos_len; i++)
    {
    	for (int j=0; j<win_nums_len; j++)
    	{
    		if (lottos[i]==win_nums[j])
    			count++;
    	}
    }
    min=count;
    max=count+count_zero;
    
    if (min==0 || min==1)
    {
    	min_rank=6;
    }
    else
    {
    	min_rank=7-min;
    }
 
    if (max==0 || max==1)
    {
    	max_rank=6;
    }
    else
    {
    	max_rank=7-max;
    }  	
    
    int minmax[2] = {max_rank, min_rank};
    int* answer = (int*)malloc(sizeof(int)*2);
    
    answer=minmax;
    printf("%d %d", answer[0], answer[1]);
    return answer;
}


int main()
{
	int a=0;
	int lo[6]={45, 4, 35, 20, 3, 9};
	int win[6]={20, 9, 3, 45, 4, 35};
	int* ans;
	ans=solution(lo,sizeof(lo)/sizeof(int),win,sizeof(win)/sizeof(int));
	
	return 0;
}
