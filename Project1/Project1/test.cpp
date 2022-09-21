#include <iostream>
#define MAX 101
using namespace std;

int n;
int res;

int factorial(int a)
{
	if (a<=1) return 1;
	return a*factorial(a-1);
}

int main()
{
	cin>>n;
	res=factorial(n);
	cout<<res;


    return 0;
}

