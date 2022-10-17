#include <iostream>
#include <vector>
using namespace std;

long long square(long long a, long long b)
{
	long long res=1;
	for (int i=0; i<b; i++)
	{
		res=res*a;
	}
	
	return res;
}

int main()
{
	string A, B, C, D;
	cin>>A>>B>>C>>D;
	
	A=A+B; //1020
	C=C+D; //3040
	
	long long a=0;
	long long c=0;
	
	for (int i=0; i<A.size(); i++) //A.size()=4
	{
		a+=(A[i]-'0')*square(10,A.size()-i-1);
	}
	
	for (int i=0; i<C.size(); i++) //A.size()=4
	{
		c+=(C[i]-'0')*square(10,C.size()-i-1);
	}
	
	printf("%lld\n", a+c);
	
	return 0;	
}
