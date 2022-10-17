#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;

void D(int x)
{
	if (x==1){
		return;
	}
	else
	{
		if (x%2==0)
		{
			x/=2;
			cout<<x<<endl;
			D(x);
		}
		else
		{
			x=3*x+1;
			cout<<x<<endl;
			D(x);
		}
	}
}

int main()
{	
	cin>>n;
	cout<<n<<endl;
	D(n);

	return 0;	
}
