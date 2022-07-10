#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int T;
	scanf("%d",&T);
	int cnt=0;
	for(int i = 0; i<T; i++)
	{
		char arr[51];
		scanf("%s", arr);
		
		for (int i=0; i<strlen(arr); i++)
		{
			if (arr[i]=='(')
				cnt++;
			else if (arr[i]==')')
				cnt--;
				
			if (cnt<0)
			{
				break;
			}
		}
	}
	

	if (cnt==0)
		printf("YES\n");
	else
		printf("NO\n");
	
    return 0;
}


