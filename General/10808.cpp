#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	char S[101]={0,};
	int arr[200]={0,};
	
	scanf("%s", S);
	
	for (int i = 0; i<strlen(S); i++)
	{
		arr[S[i]]++;
	}
	
	for(int i = 'a'; i<='z'; i++)
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}
