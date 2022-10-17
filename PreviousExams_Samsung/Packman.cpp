#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 4
#define DIR_M 8
#define DIR_P 4
using namespace std;

int m,t,r,c;

int map[MAX][MAX];
int map_egg[MAX][MAX];
int map_body[MAX][MAX];


int visited[MAX][MAX];

int dir_xm[DIR_M]={-1,-1,0,1,1,1,0,-1};
int dir_ym[DIR_M]={0,-1,-1,-1,0,1,1,1};

int dir_xp[DIR_M]={-1,0,1,0};
int dir_yp[DIR_M]={0,-1,0,1};


struct _Loc{
	int x;
	int y;
	int dir;
} Loc;

struct _route {
	int dir1;
	int dir2;
	int dir3;
	int kill;
} route;

vector<_Loc> M;
vector<_Loc> E;
vector<_route> v_route;
_Loc P;

void input()
{
	cin>>m>>t;
	cin>>r>>c;
	P.x=r-1;
	P.y=c-1;
	for (int i=0; i<m; i++)
	{
		cin>>Loc.x>>Loc.y>>Loc.dir;
		Loc.x-=1;
		Loc.y-=1;
		Loc.dir-=1;
		map[Loc.x][Loc.y]=1;
		M.push_back({Loc.x,Loc.y,Loc.dir});
	}
}

void replicate()
{
	for (int i=0; i<M.size(); i++)
	{
		map_egg[M[i].x][M[i].y]=1;
		E.push_back({M[i].x,M[i].y,M[i].dir});
	}
}

bool outofrange(int x, int y)
{
	return (x<0||y<0||x>=MAX||y>=MAX);
}
	
int move()
{
	for (int i=0; i<M.size(); i++)
	{
		bool move_bool = false;
		int cnt=1;
		while (1)
		{
			int nx=M[i].x+dir_xm[M[i].dir%8];
			int ny=M[i].y+dir_ym[M[i].dir%8];
			if (outofrange(nx,ny)==1||map_body[nx][ny]!=0||((nx==P.x) && (ny==P.y)))
			{
				M[i].dir++;
				cnt++;
				continue;
			}
			
			if (cnt==8)
			{
				break;
			}
			
			M[i].x=nx;
			M[i].y=ny;
			M[i].dir=M[i].dir;
			break;
		}
	}
	
	for (int i=0; i<MAX; i++)
	{
		for (int j=0; j<MAX; j++)
		{
			map[i][j]=0;
		}
	}
	
	for (int i=0; i<M.size(); i++)
	{
		map[M[i].x][M[i].y]+=1;
	}
}
			
void print()
{
	cout<<"map"<<endl;
	for (int i=0; i<MAX; i++)
	{
		for (int j=0; j<MAX; j++)
		{
			cout<<map[i][j];
		}
		cout<<endl;
	}
	
	cout<<"dir"<<endl;
	for (int i=0; i<M.size(); i++)
	{
		cout<<M[i].dir<<" "<<endl;
	}

	cout<<"eggmap"<<endl;
	for (int i=0; i<MAX; i++)
	{
		for (int j=0; j<MAX; j++)
		{
			cout<<map_egg[i][j];
		}
		cout<<endl;
	}

	cout<<"visited"<<endl;
	for (int i=0; i<MAX; i++)
	{
		for (int j=0; j<MAX; j++)
		{
			cout<<visited[i][j];
		}
		cout<<endl;
	}
	
	for (int i=0; i<v_route.size(); i++)
	{
		cout<<v_route[i].dir1<<" "<<v_route[i].dir2<<" "<<v_route[i].dir3<<" "<<v_route[i].kill<<endl;
	}
}


void DFS(int x, int y, int cnt, _route info)
{
	visited[x][y]=1;
	cnt++;
	cout<<"here: "<<x<<" "<<y<<" "<<cnt<<endl;
	if (cnt==5)
	{
		v_route.push_back(info);
		return;
	}
	else
	{
		info.kill+=map[x][y];
		for (int d=0; d<4; d++)
		{
			int nx=x+dir_xp[d];
			int ny=y+dir_yp[d];
			if (outofrange(nx,ny)) continue;
			if (visited[nx][ny]) continue;
			if (cnt==1) info.dir1=d;
			else if (cnt==2) info.dir2=d;
			else if (cnt==3) info.dir3=d;
			DFS(nx,ny,cnt,info);
		}
	}
}


void eat()
{
	DFS(P.x,P.y,1,route);
}

int main()
{
	input();
	replicate();
	move();
	eat();
	print();

    return 0;
}
