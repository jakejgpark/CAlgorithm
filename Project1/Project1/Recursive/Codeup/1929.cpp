#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;

void D(int x)
{
	if (x==1){
	}
	else
	{
		if (x%2==0)
		{
			D(x/2);
		}
		else
		{
			D(3*x+1);
		}
	}
	cout<<x<<endl;
}

int main()
{	
	cin>>n;
	D(n);
	return 0;	
}
