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
    int rank[7] = {6,6,5,4,3,2,1};
    int* answer = (int*)malloc(sizeof(int)*2);

    for (int i=0; i<lottos_len; i++)
    {
        if (lottos[i]==0)
        {
            count_zero++;
        }
        for (int j=0; j<win_nums_len; j++)
        {
            if (lottos[i]==win_nums[j])
                count++;
        }
    }
    printf("%d\n", count_zero);
	printf("%d %d", rank[count+count_zero], rank[count+count]);
    answer[0]=rank[count+count_zero];
	answer[1]=rank[count+count];

    return answer;
}


int main()
{
	int a=0;
	int lo[6]={44, 1, 0, 0, 31, 25};
	int win[6]={31, 10, 45, 1, 6, 19};

	solution(lo,sizeof(lo)/sizeof(int),win,sizeof(win)/sizeof(int));
	
	return 0;
}
