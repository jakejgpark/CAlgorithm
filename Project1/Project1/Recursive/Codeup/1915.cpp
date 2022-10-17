#include <iostream>
using namespace std;

int fibbo(int a){
	if (a==1 || a==2)
	{
		return 1;
	}
	else
	{
		return fibbo(a-1)+fibbo(a-2);
	}
}

int main()
{
    int n;
    
    cin>>n;
    cout<<fibbo(n);
}
