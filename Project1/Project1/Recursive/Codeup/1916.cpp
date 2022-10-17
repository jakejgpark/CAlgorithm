#include <iostream>
#define MAX 210
using namespace std;

long long  arr[MAX]={0,1,1};

long long fibbo(int a){
	if (arr[a]==0)
	{
		arr[a]=fibbo(a-1)%10009+fibbo(a-2)%10009;
		return arr[a]%10009;
	}
	else
	{
		return arr[a]%10009;
	}
}

int main()
{
    int n;
    cin>>n;
    cout<<fibbo(n)%10009;
}
