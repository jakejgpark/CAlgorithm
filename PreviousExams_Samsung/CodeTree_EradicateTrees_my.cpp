#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 25
using namespace std;


int MAP[MAX][MAX];
int KILL[MAX][MAX];
int rx[4]={1,1,-1,-1};
int ry[4]={-1,1,-1,1};
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
int n,m,k,c;
int near_e;
int near_t;

struct _Multi{
	int a;
	int b;
};

vector<_Multi> Multi;

void input()
{
	cin>>n>>m>>k>>c;
	
	for (int x=0; x<n; x++)
	{
		for (int y=0; y<n; y++)
		{
			cin>>MAP[x][y];
		}
	}
}

void treegrowing()
{
	for (int x=0; x<n; x++)
	{
		for (int y=0; y<n; y++)
		{
			near_t=0;
			if (MAP[x][y]<=0) continue;
			
			for (int d=0; d<4; d++)
			{
				int xx=x+dx[d];
				int yy=y+dy[d];
				
				if ((xx<0) || (yy<0) || (xx>=n) || (yy>=n)) continue;
				
				if (MAP[xx][yy]>0) near_t++;
			}
			MAP[x][y]+=near_t;
		}
	}
}

void multipletree()
{
	int NT[MAX][MAX]={0,};
	for (int x=0; x<n; x++)
	{
		for (int y=0; y<n; y++)
		{
			near_e=0;
			Multi.clear();
			if (MAP[x][y]<=0) continue;
			
			for (int i=0; i<4; i++)
			{
				int xx=x+dx[i];
				int yy=y+dy[i];
				
				if ((xx<0) || (yy<0) || (xx>=n) || (yy>=n)) continue;
				
				if (MAP[xx][yy]==0)
				{
					near_e++;
					Multi.push_back({xx,yy});
				}
			}
			
			for (int mul=0; mul<Multi.size(); mul++)
			{
				NT[Multi[mul].a][Multi[mul].b]+=MAP[x][y]/near_e;
			}			
		}
	}
	
	for (int x=0; x<n; x++)
	{
		for (int y=0; y<n; y++)
		{
			MAP[x][y]+=NT[x][y];
		}
	}
}

void print()
{
	for (int x=0; x<n; x++)
	{
		for (int y=0; y<n; y++)
		{
			cout<<MAP[x][y]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	freopen("input.txt","rt",stdin);
	input();
	treegrowing();
	multipletree();
	print();
	
	return 0;
}

