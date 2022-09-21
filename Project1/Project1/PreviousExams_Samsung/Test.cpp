#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 25

int T[MAX][MAX];
int R[MAX][MAX];

int N,M,K,C;

// 상하좌우 (나무번식 방향)
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int near_t = 0;
int near_e = 0;

struct PAIR{
    int a;
    int b;
};


int main()
{
	vector<PAIR> M;
	M.push_back({2,1});

	for (int i=0; i<M.size(); i++)
	{
		cout<<M[i].a<<" "<<M[i].b<<" "<<endl;
	}
	
	return 0;
}

