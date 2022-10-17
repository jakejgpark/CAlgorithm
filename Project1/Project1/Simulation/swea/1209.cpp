#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 100
using namespace std;

int tc,n;
int map[MAX][MAX];
int r,c,diag_1,diag_2;
int r_max=-1,c_max=-1,diag_max=-1;
int ans;

void input()
{
	for (int i=0; i<MAX; i++)
	{
		for (int j=0; j<MAX; j++)
		{
			cin>>map[i][j];
		}
	}
}

void count_r_c()
{
	/* row */ /* column */
	c_max=0;
	r_max=0;
	for (int i=0; i<MAX; i++)
	{
		r=0;
		for (int j=0; j<MAX; j++)
		{
			r+=map[i][j];
		}
		if (r>=r_max) r_max=r;
		
		c=0;
		for (int j=0; j<MAX; j++)
		{
			c+=map[j][i];
		}
		if (c>=c_max) c_max=c;
	}
}

void diag_func()
{
	diag_1=0;
	diag_2=0;
	diag_max=0;
	int a=0;
	int b=0;
	int c=0;
	int tmp=MAX-1;
	//inc
	for (int i=0; i<MAX; i++)
	{
		diag_1+=map[a++][b++];
	}
	
	for (int i=0; i<MAX; i++)
	{
		diag_2+=map[tmp--][c++];
	}
	
	if (diag_1>=diag_2) diag_max=diag_1;
	else diag_max=diag_2;
}
				

int main()
{
	freopen("input.txt","rt",stdin);
	
	for (int i=0; i<10; i++)
	{
		cin>>tc;
		input();
		count_r_c();
		diag_func();
	
		if (r_max>=c_max)
		{
			ans=r_max;
		}
		else
		{
			ans=c_max;
		}
		if (diag_max>=ans) ans=diag_max;
		cout<<"#"<<i+1<<" "<<ans<<endl;
	}
	return 0;
}

