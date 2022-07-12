#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int T;
	scanf("%d",&T);
	
	for(int i = 0; i<T; i++)
	{
		char arr[51];
		int cnt=0;
		scanf("%s", arr);
		
		for (int i=0; i<strlen(arr); i++)
		{
			if (arr[i]=='(')
				cnt++;
			else if (arr[i]==')')
				cnt--;
			if (cnt<0)
			{
				printf("NO\n");
				break;
			}
			if (i==(strlen(arr)-1))
			{
				if (cnt==0)
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
    return 0;
}


