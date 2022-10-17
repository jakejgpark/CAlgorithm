#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int k,n;

int SuperSum(int a, int b)
{
	return a;
}

int main()
{	
	while( scanf("%d %d", &k, &n) != EOF )
	{	
		printf("%d\n", SuperSum(k, n));
	}
	
	return 0;	
}
