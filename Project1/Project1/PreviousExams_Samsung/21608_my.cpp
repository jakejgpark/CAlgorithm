#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 25
using namespace std;


struct STUDENT{
	int Num;
	int Friend[4];
};

struct POSITION{
	int x;
	int y;
	int Near_Friend;
	int Near_Empty;
};

int n;
vector<STUDENT> Student;
vector<POSITION> Position;
int sum=0;
int MAP[MAX][MAX]={0,};
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool cmp(POSITION A, POSITION B)
{
	if(A.Near_Friend>=B.Near_Friend)
	{
		if (A.Near_Friend==B.Near_Friend)
		{
			if (A.Near_Empty>=B.Near_Empty)
			{
				if(A.Near_Empty==B.Near_Empty)
				{
					if (A.x<=B.x)
					{
						if(A.x==B.x)
						{
							if(A.y<B.y)
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
		return true;
	}
	return false;
}

void P()
{
	for (int i=0; i<n*n; i++)
	{
		POSITION pos={};
		Position.clear();
		for (int x=0; x<n; x++)
		{
			for (int y=0; y<n; y++)
			{
				if(MAP[x][y]!=0) continue;
				
				int _friend=0;
				int _empty=0;
				
				for (int j=0; j<4; j++)
				{
					int nx=x+dx[j];
					int ny=y+dy[j];

					if (nx<0||ny<0||nx>=n||ny>=n) continue;
					else
					{
						if (MAP[nx][ny]==0) _empty++;
						else
						{
							for(int k=0; k<4; k++)
							{
								if (MAP[nx][ny]==Student[i].Friend[k])
								{
									_friend++;
									break;
								}
							}
						}
					}
				}
				pos.Near_Empty=_empty;
				pos.Near_Friend=_friend;
				pos.x=x;
				pos.y=y;
				Position.push_back(pos);
			}
		}
		sort(Position.begin(),Position.end(),cmp);
		int copy_x=Position[0].x;
		int copy_y=Position[0].y;
		MAP[copy_x][copy_y]=Student[i].Num;
		
//		for (int z=0; z<n; z++)
//		{
//			for (int w=0; w<n; w++)
//			{
//				cout<<MAP[z][w];
//			}
//			cout<<endl;
//		}
	}
}
				
			

void Input()
{
	cin>>n;
	int a,b,c,d,e;
	STUDENT temp;
	for (int i=0; i<n*n; i++)
	{
		cin>>a>>b>>c>>d>>e;
		temp.Num=a;
		temp.Friend[0]=b;
		temp.Friend[1]=c;
		temp.Friend[2]=d;
		temp.Friend[3]=e;
		Student.push_back(temp);
	}
//	for (int i=0; i<Student.size(); i++)
//	{
//		cout<<Student[i].Num<<endl;
//	}
}

bool cmp_order(STUDENT A, STUDENT B)
{
	return A.Num<B.Num;
}

void calculation()
{
	sort(Student.begin(), Student.end(), cmp_order);
	for(int x=0; x<n; x++)
	{
		for(int y=0; y<n; y++)
		{
			int Near_friend=0;
			for (int j=0; j<4; j++)
			{
				int nx=x+dx[j];
				int ny=y+dy[j];
				
				if(nx<0||ny<0||nx>=n||ny>=n) continue;
				else
				{
					for (int k=0; k<4; k++)
					{
//						cout<<"Student:Friend: "<<Student[MAP[x][y]-1].Friend[k]<<endl;
						if (MAP[nx][ny]==Student[MAP[x][y]-1].Friend[k])
						{
							Near_friend++;
						}
					}
				}
			}
//			cout<<"Near_Friend: "<<Near_friend<<endl;
			if (Near_friend==4)
			{
				sum+=1000;
			}
			else if (Near_friend==3)
			{
				sum+=100;
			}
			else if (Near_friend==2)
			{
				sum+=10;
			}
			else if (Near_friend==1)
			{
				sum+=1;
			}
		}
	}
}

int main()
{
	Input();
	P();
	calculation();
//	for (int z=0; z<n; z++)
//	{
//		for (int w=0; w<n; w++)
//		{
//			cout<<MAP[z][w];
//		}
//		cout<<endl;
//	}
	
	cout<<sum;

	return 0;
}

