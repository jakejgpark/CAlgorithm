#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> v;
	int cnt;
	vector<string> str_arr;
	string str;
	getline(cin,str);
	str_arr.emplace_back(str);
	
	cnt=str.length(); /* "baekjoon" */
	
	
	for (int i=0; i<cnt; i++)
	{
		v.emplace_back(str.substr(i,cnt-i));
	}
	
	sort(v.begin(), v.end());
	
	for (int i=0; i<v.size(); i++)
	{
		cout<<v[i]<<endl;
	}
	
	return 0;	
}
