#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 25
using namespace std;

int n,m,k,c;

int T[MAX][MAX];
int R[MAX][MAX];

int near_t;
int near_e;

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

int rx[4]={1,1,-1,-1};
int ry[4]={1,-1,1,-1};

int kx, ky;
int result;

struct Grow{
	int x;
	int y;
	Grow(int a, int b)
	{
		x = a;
		y = b;
	}
};

vector<Grow> MT;

struct Killer{
	int x;
	int y;
	int cnt;
};

vector<Killer> Killers;

bool cmp(Killer a, Killer b)
{
	if (a.x<=b.x)
	{
		if (a.x==b.x)
		{
			if (a.y<b.y)
			{
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

void Input()
{
	cin>>n>>m>>k>>c;
	for (int x=0; x<n; x++)
	{
		for (int y=0; y<n; y++)
		{
			cin>>T[x][y];
		}
	}
}

void TreeGrowing()
{
	for (int x=0; x<n; x++)
	{
		for (int y=0; y<n; y++)
		{
			if (T[x][y]<=0) continue;
			near_t=0;
			for (int d=0; d<4; d++)
			{
				int xx=x+dx[d];
				int yy=y+dy[d];
				
				if ((xx<0)||(yy<0)||(xx>=n)||(yy>=n)) continue;
				
				if ((T[xx][yy]>0) && (R[xx][yy]==0)) near_t++;
			}
			T[x][y]+=near_t;
		}
	}
}

void MultipleTree()
{
	
	int NT[MAX][MAX]={0};
	
	for (int x=0; x<n; x++)
	{
		for (int y=0; y<n; y++)
		{
			if ((T[x][y]<=0) || (R[x][y]>0)) continue;

			near_e=0;
			MT.clear();
			for (int d=0; d<4; d++)
			{
				int xx=x+dx[d];
				int yy=y+dy[d];
				
				if ((xx<0)||(yy<0)||(xx>=n)||(yy>=n)) continue;
				if (T[xx][yy]==0 && R[xx][yy]==0)
				{
					near_e++;
					MT.push_back({xx,yy});
				}
			}
		
			for (int mt=0; mt<MT.size(); mt++)
			{
				int mul = T[x][y]/near_e;
				NT[MT[mt].x][MT[mt].y]+=mul;
			}
		}
	}
			
	for (int x=0; x<n; x++)
	{
		for (int y=0; y<n; y++)
		{
			if (T[x][y]==-1) continue;
			T[x][y]+=NT[x][y];
		}
	}
}


void RPosition()
{
	int max_count=0;
	int count=0;
	Killers.clear();
	kx=0;
	ky=0;
	
	for (int x=0; x<n; x++)
	{
		for (int y=0; y<n; y++)
		{
			if (T[x][y]<-1) continue;
			
			count=T[x][y];
			
			if(T[x][y]>0)
			{
				for(int d=0; d<4; d++)
				{
					for (int i=1; i<=k; i++)
					{
						int xx=x+rx[d]*i;
						int yy=y+ry[d]*i;
						
						if ((xx<0)||(yy<0)||(xx>=n)||(yy>=n)) break;
						if ((T[xx][yy]<=0)||(R[xx][yy]>0)) break;
						
						count+=T[xx][yy];
					}
				}
			}
			
			if (max_count<=count)
			{
				if (max_count==count)
				{
					Killers.push_back({x,y,count});
				}
				else {
					max_count=count;
					Killers.clear();
					Killers.push_back({x,y,count});
				}
			}
		}
	}
//	
//	for (int i=0; i<Killers.size(); i++)
//	{
//		cout<<Killers[i].x<<" "<<Killers[i].y<<" "<<Killers[i].cnt<<endl;
//	}
	
	sort(Killers.begin(), Killers.end(), cmp);
	kx=Killers[0].x;
	ky=Killers[0].y;
//	cout<<Killers[0].x<<" "<<Killers[0].y<<" "<<Killers[0].cnt<<endl;
}
	

void Kill()
{
	for (int d=0; d<4; d++)
	{
		for (int i=1; i<=k; i++)
		{
			int xx=kx+rx[d]*i;
			int yy=ky+ry[d]*i;
			
			if ((xx<0)||(yy<0)||(xx>=n)||(yy>=n)) break;
			if (T[xx][yy]<=0)
			{
				R[xx][yy]=c+1;
				break;
			}
			result+=T[xx][yy];
			R[xx][yy]=c+1;
			T[xx][yy]=0;
		}
	}
	result+=T[kx][ky];
	T[kx][ky]=0;
	R[kx][ky]=c+1;
//	cout<<kx<<ky<<endl;
}

void Heal()
{
	for (int x=0; x<n; x++)
	{
		for (int y=0; y<n; y++)
		{
			if (R[x][y]>0)
			{
				R[x][y]--;
			}
		}
	}
}
	

void Print()
{
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			cout<<T[i][j]<<" ";
		}
		cout<<endl;
	}
}

void total()
{
	TreeGrowing();
//	cout<<"TreeGrowing()"<<endl;
//	Print();
	MultipleTree();
//	cout<<"MultipleTree()"<<endl;
//	Print();
	RPosition();
	Kill();
//	cout<<"Kill()"<<endl;
//	Print();
	Heal();
//	cout<<"Heal()"<<endl;
//	Print();
}

int main()
{
//	freopen("input2.txt","rt",stdin);
	Input();
	
	for (int i=0; i<m; i++)
	{
		total();
	}
	cout<<result<<endl;
	return 0;
}


