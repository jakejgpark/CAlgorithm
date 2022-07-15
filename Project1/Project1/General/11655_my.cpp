#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
//	65 90 OUT OF BOUND : A(65) N(78) 
//	97 122 OUT OF IF (X>90) 97+(X-90-1)
	char S[101]={0,};
	int i=0;
	cin.getline(S,101);
	for (i=0; i<strlen(S); i++)
	{
		if (S[i]>='A'/*65*/ && S[i]<='Z') /*90*/
		{
			S[i]+=13;
			if (S[i]>90)
			{
				S[i]%=90;
				S[i]=S[i]+65-1;
			}
		}
		else if (S[i]>='a'/*97*/ && S[i]<='z') /*122*/
		{
			S[i]+=13;
			if (S[i]>='a'/*97*/ && S[i]<='z')
			{
				printf("%c",S[i]);
				continue;
			}
			else if (S[i]>122)
			{ /* e.g. 126 */
				S[i]%=122;
				S[i]=S[i]+97-1;
			}
			else if (S[i]<0)
			{
				S[i]=S[i]+128+97+5;
			}
		}
		printf("%c", S[i]);
//		printf("%d", S[i]);
	}
	
	return 0;
}
