#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

int n, map_idx;
char map[MAX][MAX];

int visit_noweak[MAX][MAX];
int visit_weak[MAX][MAX];

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

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
	return (x>=1 && y>=1 && x<=n &&y<=n);
}

void noweakness(int x, int y, char color)
{
	visit_noweak[x][y]=1;
	for (int d=0; d<4; d++)
	{
		int nx=x+dx[d];
		int ny=y+dy[d];
		
		if (inrange(nx,ny)==0) continue;
		if (visit_noweak[nx][ny]==1) continue;
		if (map[nx][ny]!=color) continue;
		
		noweakness(nx, ny, color);
	}
}

void weakness(int x, int y, char color)
{
	visit_weak[x][y]=1;
	for (int d=0; d<4; d++)
	{
		int nx=x+dx[d];
		int ny=y+dy[d];
		
		if (inrange(nx,ny)==0) continue;
		if (visit_weak[nx][ny]==1) continue;
		if ((color=='B' && map[nx][ny]!='B')||(color=='R' && map[nx][ny]=='B') || (color=='G' && map[nx][ny]=='B')) continue;
		
		weakness(nx, ny, color);
	}
}
			
int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	
	input();
	int idx=0;
	int idx2=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (visit_noweak[i][j]==false)
			{	
				noweakness(i,j,map[i][j]);
				idx++;
			}
		}
	}
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			if (visit_weak[i][j]==false)
			{
				weakness(i,j,map[i][j]);
				idx2++;
			}
		}
	}
	
	cout<<idx<<" "<<idx2;
	
	return 0;
}
