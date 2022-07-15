#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	char S[101]={0,};
	int arr[200]={0,};
	int visit[200]={0,};
	int idx=0;	
	
	for (int i = 0; i<200; i++)
	{
		arr[i]=-1;
		visit[i]=0;
	}
	
	scanf("%s", S);
	
	for (int i = 0; i<strlen(S); i++)
	{
		if (visit[S[i]]==0)
		{
			printf("check\n");
			arr[S[i]]=idx;
			visit[S[i]]=1;
		}
		idx++;
	}
	
	for(int i = 'a'; i<='z'; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}
