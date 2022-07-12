#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;


int n;
int digit_sum(int x)
{
	int sum=0;
	char digit_char[10]={0,};
	sprintf(digit_char,"%d",x);
	
	for (int i=0; digit_char[i]!='\0'; i++)
	{
		sum+=(digit_char[i]-'0');
	}
	
	
	return sum;
}


int main()
{
	int max=0;
	int idx=-1;
	scanf("%d", &n);
	int arr[n]={0,};
	int res[n]={0,};
	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
		res[i]=digit_sum(arr[i]);
	}
//	
//	for(int i=0; i<n; i++)
//	{
//		printf("%d ", res[i]);
//	}
	
	for(int i=0; i<n; i++)
	{
		if (res[i]>max)
		{
			max=res[i];
			idx=i;
		}
		else if (res[i]==max)
		{
			if (arr[i]>arr[idx])
			{
				max=arr[i];
				idx=i;
			}
		}
	}
	
	printf("%d", arr[idx]);
	
	return 0;
}
