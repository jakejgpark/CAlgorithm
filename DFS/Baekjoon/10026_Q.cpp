#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

int n, map_idx;
char map[MAX][MAX];

int visit_noweak[MAX][MAX];
int visit_weak[MAX][MAX];

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

int idx1;
int idx2;

void input()
{
	cin>>n;
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			cin>>map[i][j];
		}
	}
}

bool inrange(int x, int y)
{
	return (x>=1 && y>=1 && x<=n && y<=n);
}

void noweak(int x, int y, char color)
{
	queue<pair<int,int>> Q;
	Q.push(make_pair(x,y));
	visit_noweak[x][y]=1;
	
	while (Q.empty()==0)
	{
		int x=Q.front().first;
		int y=Q.front().second;
		Q.pop();
		
		for (int i=0; i<4; i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if (inrange(nx,ny)==0) continue;
			if (visit_noweak[nx][ny]==1) continue;
			if ((color=='R' && map[nx][ny]=='B')||(color=='G' && map[nx][ny]=='B')||
			(color=='B' && map[nx][ny]!='B')) continue;
			
			Q.push(make_pair(nx,ny));
			visit_noweak[nx][ny]=1;
		}
	}
}



void weak(int x, int y, char color)
{
	queue<pair<int,int>> Q;
	Q.push(make_pair(x,y));
	visit_weak[x][y]=1;
	
	while (Q.empty()==0)
	{
		int x=Q.front().first;
		int y=Q.front().second;
		Q.pop();
		
		for (int i=0; i<4; i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if (inrange(nx,ny)==0) continue;
			if (visit_weak[nx][ny]==1) continue;
			if (color!=map[nx][ny]) continue;
			
			Q.push(make_pair(nx,ny));
			visit_weak[nx][ny]=1;
		}
	}
}

			
int main()
{
	input();
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (visit_weak[i][j]==0)
			{
				idx1++;
				weak(i,j, map[i][j]);
			}
		}
	}
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (visit_noweak[i][j]==0)
			{
				idx2++;
				noweak(i,j, map[i][j]);
			}
		}
	}
	
	cout<<idx1<<" "<<idx2<<endl;
	
	return 0;
}
