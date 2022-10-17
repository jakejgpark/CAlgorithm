#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int T;
int arr[10001];
int visit[10001]={0,};
int arr_index=0;
int size_cnt=0;
int empty_cnt=0;
int pop_cnt=0;
int top_cnt=0;
char command[10];
char s0[10];
char s1[10]="push";
char s2[10]="pop";
char s3[10]="top";
char s4[10]="size";
char s5[10]="empty";
int push_num;


void push(int X)
{
	arr[arr_index]=X;
	visit[arr_index]=1;
	arr_index++;
	printf("push index: %d", arr_index);
}

void pop()
{
	for (int i = 0; i<arr_index+1; i++)
	{
		if (visit[i]==1)
		{
			pop_cnt++;
		}
	}
	
	if (pop_cnt==0)
	{
		printf("%d", -1);
	}
	else
	{
		arr_index--;
		printf("%d", arr[arr_index]);
		visit[arr_index]=0;	
	}
	pop_cnt=0;
}


void size()
{
	for (int i =0; i<arr_index+1; i++)
	{
		if (visit[i]==1)
		{
			size_cnt++;
		}
	}
	printf("%d", size_cnt);
	size_cnt = 0;
}

void empty()
{
	for (int i =0; i<arr_index+1; i++)
	{
		if (visit[i]==1)
		{
			empty_cnt++;
		}
	}
	if(empty_cnt==0)
	{
		printf("%d",1);
	}
	else
	{
		printf("%d",0);
	}
	empty_cnt=0;
}

void top()
{
	for (int i = 0; i<arr_index+1; i++)
	{
		if (visit[i]==1)
		{
			top_cnt++;
		}
	}
	
	if (top_cnt==0)
	{
		printf("%d", -1);
	}
	else
	{
		for (int i=1; i<arr_index+1; i++)
		{
			if (visit[i-1]!=visit[i])
			{
				printf("%d",visit[i-1]);
			}
		}
	}
	top_cnt=0;
}

int main(void)
{
	scanf("%d", &T);
	for (int i=0; i<T; i++)
	{
		scanf("%s", s0);
		
		if (strcmp(s0,s1)==0)
		{
			scanf("%d",&push_num);
			push(push_num);
		}
		else if (strcmp(s0,s2)==0)
		{
			pop();
		}
		else if (strcmp(s0,s3)==0)
		{
			top();
		}		
		else if (strcmp(s0,s4)==0)
		{
			size();
		}
		else if (strcmp(s0,s5)==0)
		{
			empty();
		}
		
	}
//	for (int i=0; i<arr_index+1; i++)
//	{
//		printf("%d", visit[i]);
//	}
	return 0;
}
