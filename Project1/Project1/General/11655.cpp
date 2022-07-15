#include <stdio.h>
int main(){
	char str[101];
	gets(str);
	for(int i = 0; str[i]!=NULL; i++){
		char c = str[i];
		if(c>='a' && c<='z') c = (c-'a'+13) % 26 + 'a';
		else if(c>='A' && c <='Z') c = (c-'A'+13)%26 + 'A';
		printf("%c",c);
	}
	return 0;
}
