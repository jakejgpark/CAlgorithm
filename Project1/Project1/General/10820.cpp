#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n=0;
	int low=0;
	int upp=0;
	int num=0;
	int space=0;
	
	scanf("%d", &n);
	string str1;
	for (int i=0; i<n; i++)
	{ 
		getline(cin, str1);
	}
//		for (int j = 0; j<str.length(); j++)
//		{
//			if (str[j]>=65 && str[j]<=90)
//			{
//				upp++;
//			}
//			else if (str[j]>=97 && str[j]<=97+25)
//			{
//				low++;
//			}
//			else if (str[j]==' ')
//			{
//				space++;
//			}
//			else if ((str[j]-'0')>=0 && (str[j]-'0')<=9)
//			{
//				num++;
//			}
//		}
//		printf("%d %d %d %d", low, upp, num, space);
//	}
	return 0;
}
