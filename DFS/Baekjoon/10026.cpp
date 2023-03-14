#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

int map[MAX][MAX];
int map_noweak[MAX][MAX];
int map_weak[MAX][MAX];
int n, map_idx;
int visit_noweak[MAX][MAX];
int visit_weak[MAX][MAX];

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

vector<pair<int, int>> v;

// R=1, G=2, B=3

void input()
{
	cin>>n;
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			char a;
			cin>>a;
			
			if (a=='R')
			{
				map[i][j]=1;
			}
			else if (a=='G')
			{
				map[i][j]=2;
			}
			else if (a=='B')
			{
				map[i][j]=3;
			}
		}
	}
}

bool inrange(int x, int y)
{
	return (x>=1 && y>=1 && x<=n &&y<=n);
}

void print()
{
	cout<<"just map"<<endl;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			cout<<map[i][j];
		}
		cout<<endl;
	}

	cout<<"weak map"<<endl;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			cout<<map_weak[i][j];
		}
		cout<<endl;
	}
	
}

bool flag=0;
bool flag2=0;

void noweakness(int x, int y, int color, int idx)
{
	if (visit_noweak[x][y]==1) 
	{
		flag = false;
		return;
	}
	visit_noweak[x][y]=1;
	flag=true;
	for (int d=0; d<4; d++)
	{
		int nx=x+dx[d];
		int ny=y+dy[d];
		
		if (inrange(nx,ny)==0) continue;
		if (visit_noweak[nx][ny]==1) continue;
		if (map[nx][ny]!=color) continue;
		
		noweakness(nx, ny, color, idx);
	}
}

void weakness(int x, int y, int color, int idx)
{
	if (visit_weak[x][y]==1) 
	{
		flag2 = false;
		return;
	}
	visit_weak[x][y]=1;
	map_weak[x][y]=idx;
	flag2=true;
	for (int d=0; d<4; d++)
	{
		int nx=x+dx[d];
		int ny=y+dy[d];
		
		if (inrange(nx,ny)==0) continue;
		if (visit_weak[nx][ny]==1) continue;
		if ((color==3 && map[nx][ny]!=3)||(color==1 && map[nx][ny]==3) || (color==2 && map[nx][ny]==3)) continue;
		
		weakness(nx, ny, color, idx);
	}
}


			
int main()
{
	input();
	int idx=0;
	int idx2=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			flag=false;
			noweakness(i,j,map[i][j],idx);
			if (flag==1)
			{
//				cout<<flag<<" "<<i<<" "<<j<<endl;
				idx++;
			}
		}
	}
	
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			flag2=false;
			weakness(i,j,map[i][j],idx2);
			if (flag2==1)
			{
//				cout<<flag2<<" "<<i<<" "<<j<<endl;
				idx2++;
			}
		}
	}
	
	cout<<idx<<" "<<idx2;
//	print();
	
	return 0;
}
