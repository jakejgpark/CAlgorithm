#include <iostream>
#include <algorithm>
#define MAX 10
using namespace std;

int n;
int arr[4]={0,1,};

int main()
{
	cin>>n;
	int x,y,tmp;
	
	for (int i=0; i<n; i++)
	{
		cin>>x>>y;
		tmp=arr[x];
		arr[x]=arr[y];
		arr[y]=tmp;
	}
	
	for (int i=1; i<4; i++)
	{
		if (arr[i]==1) cout<<i;
	}
	
    return 0;
}

