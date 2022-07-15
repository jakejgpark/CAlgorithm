#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	while (getline(cin,str))
	{
		int low=0, upp=0, num=0, space=0;
		
		for (int i=0; i<str.size(); i++)
		{
			if (str[i]==' ')
			{
				space++;
			}
			else if ((str[i]>='a') && (str[i]<='z'))
			{
				low++;
			}
			else if ((str[i]>='A') && (str[i]<='Z'))
			{
				upp++;
			}
			else if ((str[i]-'0')>=0 && (str[i]-'0')<=9)
			{
				num++;
			}
		}
		printf("%d %d %d %d\n", low, upp, num, space);
	}
	return 0;
}
