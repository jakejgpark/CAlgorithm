#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct gas{
	int x;
	int y;
};

int n;
vector<gas> v;

bool cmp(gas A, gas B)
{
	if (A.x<B.x)
	{
		return true;
	}
	return false;
}

int main()
{
    cin>>n;
    gas a;
    for (int i=0; i<n; i++)
    {
    	cin>>a.x>>a.y;
    	v.push_back({a.x,a.y});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for (int i=0; i<n; i++)
    {
    	cout<<v[i].x<<" "<<v[i].y<<endl;
    }
    
    return 0;
}
