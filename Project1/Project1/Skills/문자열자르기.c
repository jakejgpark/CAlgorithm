#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int arr[1000][1000];
int cnt[1000];

//https://dojang.io/mod/page/view.php?id=358

int* solution(const char* id_list[], size_t id_list_len, const char* report[], size_t report_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)calloc(id_list_len,sizeof(int));
    char* str, text[21];
    
    for (int i = 0; i<report_len; i++)
    {
    	strcpy(text, report[i]);
    	str = strtok(text, " ");
    	for (int j = 0; j<id_list_len; j++)
    	{
    		if (strcmp(str, id_list[j])==0)
    		{
    			str = strtok(NULL, " ");
    			for (int l = 0; l <id_list_len; l++)
    			{
    				if (strcmp(str, id_list[l])==0)
    				{
    					if(arr[j][l]==0)
    					{
    						arr[j][l]=1;
    						cnt[l]++;
    					}
    					break;
    				}
    			}
    			break;
    		}
    	}
    }
    
    
    for (int i = 0; i < id_list_len; i++)
    {
    	if (cnt[i]>=k)
    	{
    		for(int j = 0; j<id_list_len; j++)
    		{
    			if(arr[j][i]==1)
    			{
    				answer[j]++;
    			}
    		}
    	}
    }
		  return answer;
}		  

