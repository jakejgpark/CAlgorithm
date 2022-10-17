#include <iostream>
#define MAX 10
using namespace std;

int visit[MAX];
int n,k;

int input()
{
	cin>>n>>k;
}

void DFS(int a, int b)
{
	if (a==k+1)
	{
		return;
	}
	else
	{
		DFS(a+1,b);
		cout<<b;
		DFS(a+1,b-1);
	}
}

int main()
{
	input();

	DFS(1, n);
	return 0;
}
