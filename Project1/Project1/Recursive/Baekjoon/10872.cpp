#include <iostream>
#include <algorithm>
#define MAX 55
using namespace std;

int n;
int arr[MAX];

struct size {
	int x;
	int y;
};

int main()
{
	cin>>n;
	struct cvsize S[MAX];
	for (int i=0; i<n; i++)
	{
		arr[i]=1;
	}
	
	for (int i=0; i<n; i++)
	{
		cin>>S[i].x>>S[i].y;
	}
	
	
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			
			if ((S[i].x<S[j].x) && (S[i].y<S[j].y)) // 다른 사람이 덩치가 큰 경우 본인 순위는 하나 올라감. 
			{
				arr[i]++;
			}
		}
	}
	
	for (int i=0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	
    return 0;
}

