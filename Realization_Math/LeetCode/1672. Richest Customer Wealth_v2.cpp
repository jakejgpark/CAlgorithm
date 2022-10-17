#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
int max_value=-1;
int value;

int solution()
{
	v.push_back({1,2,3});
	v.push_back({4,5,6});
	
	
	for (int i=0; i<v.size(); i++)
	{
		int tmp=0;
		for (int j=0; j<v[i].size(); j++)
		{
			tmp+=v[i][j];
		}
		
		if (tmp>max_value)
		{
			max_value=tmp;
		}
	}
	
	return max_value;
}

int main()
{
	cout<<solution();
			
	return 0;
}
