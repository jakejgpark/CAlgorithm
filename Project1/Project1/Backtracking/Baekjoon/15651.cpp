#include <iostream>
#define MAX 8
using namespace std;

int N;
int M;
int arr[MAX];
int dis[MAX];

int D(int cnt) //e.g. N=3, M=2
{
	if (cnt==M)
	{
		for (int i=1; i<=M; i++)
		{
			cout<<dis[i]<<" ";
		}
		cout<<endl;
	}
	else
	{
		for (int i=1; i<=N; i++)
		{
			dis[cnt]=i;
			D(cnt+1);
		}
	}
}

int main()
{
	cin>>N>>M;
	for (int i=1; i<=N; i++)
	{
		arr[i]=i;
	}
	
	D(0);
	
	return 0;
}

