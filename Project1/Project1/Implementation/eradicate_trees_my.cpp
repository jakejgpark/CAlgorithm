#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 25
using namespace std;

int map[MAX][MAX];
int map_r[MAX][MAX];
int n,m,k,c;
int near_t;
int near_e;
int total;

int kx=0;
int ky=0;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int rx[4]={1,1,-1,-1};
int ry[4]={1,-1,1,-1};

struct nearempty
{
	int x;
	int y;
};

vector<nearempty> near_empty;

struct Position
{
	int x;
	int y;
	int cnt;
};

vector<Position> position_kill;

bool cmp(Position A, Position B)
{
	if (A.cnt>=B.cnt)
	{
		if (A.cnt==B.cnt)
		{
			if (A.x<=B.x)
			{
				if (A.x==B.x)
				{
					if (A.y<B.y)
					{
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}


void input()
{
	cin>>n>>m>>k>>c;
	
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cin>>map[i][j];
		}
	}
}

void treegrowing()
{
	for (int x=0; x<n; x++)
	{
		for (int y=0; y<n; y++)
		{
			if (map[x][y]<=0) continue;
			near_t=0;
			for (int d=0; d<4; d++)
			{
				int xx=x+dx[d];
				int yy=y+dy[d];
				
				if ((xx<0)||(yy<0)||(xx>=n)||(yy>=n)) continue;
				
				if (map[xx][yy]>0)
				{
					near_t++;
				}
			}
			map[x][y]+=near_t;
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
			if (map[x][y]<=0) continue;
			near_e=0;
			near_empty.clear();
			for (int d=0; d<4; d++)
			{
				int xx=x+dx[d];
				int yy=y+dy[d];
				
				if ((xx<0)||(yy<0)||(xx>=n)||(yy>=n)) continue;
				
				if ((map[xx][yy]==0) && (map_r[xx][yy]==0))
				{
					near_e++;
					near_empty.push_back({xx,yy});
				}
			}
			for (int mt=0; mt<near_empty.size(); mt++)
			{
				NT[near_empty[mt].x][near_empty[mt].y]+=map[x][y]/near_e;
			}
		}
	}
	for (int x=0; x<n; x++)
	{
		for (int y=0; y<n; y++)
		{
			map[x][y]+=NT[x][y];
		}
	}
}
					 
void Positioncheck()
{
	int result=0;
	int max_val=0;
	
	position_kill.clear();
	for (int x=0; x<n; x++)
	{
		for (int y=0; y<n; y++)
		{
			if (map[x][y]<=0) continue;
			
			result=map[x][y];
			
			for (int i=0; i<4; i++)
			{
				for (int d=1; d<=k; d++)
				{
					int xx=x+rx[i]*d;
					int yy=y+ry[i]*d;
					
					if ((xx<0)||(yy<0)||(xx>=n)||(yy>=n)) break;
					if (map[xx][yy]==-1 || map[xx][yy]==0) break;
					
					result+=map[xx][yy];
				}
			}
			
			if (result>=max_val)
			{
				max_val=result;
				position_kill.push_back({x,y,result});
			}
		}
	}
	sort(position_kill.begin(),position_kill.end(),cmp);
	if (position_kill.size()!=0)
	{
		kx=position_kill[0].x;
		ky=position_kill[0].y;
	}
}

void Kill()
{
	total+=map[kx][ky];
	map[kx][ky]=0;
	map_r[kx][ky]=c+1;
	for (int d=0; d<4; d++)
	{
		for (int i=1; i<=k; i++)
		{
			int xx=kx+rx[d]*i;
			int yy=ky+ry[d]*i;
			if ((xx<0)||(yy<0)||(xx>=n)||(yy>=n)) break;
			if (map[xx][yy]==-1 || map[xx][yy]==0) 
			{
				map_r[xx][yy]=c+1;
				break;
			}
			
			map_r[xx][yy]=c+1;
			total+=map[xx][yy];
			map[xx][yy]=0;
		}
	}
}

void Heal()
{
	for(int x=0; x<n; x++)
	{
		for (int y=0; y<n; y++)
		{
			if (map_r[x][y]>0) map_r[x][y]--;
		}
	}
}

void print()
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
//	freopen("input3.txt","rt",stdin);
	input();
	for (int i=0; i<m; i++)
	{
		treegrowing();
		multipletree();
		Positioncheck();
//		print();
		Kill();
		Heal();
//		print();
	}
	cout<<total;
	
	return 0;
}

