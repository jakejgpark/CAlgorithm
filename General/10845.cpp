#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> v;
	int cnt;
	cin>>cnt;
	
	while(cnt--){
		string cmd;
		cin >> cmd;
		
		if (cmd=="push"){
			int n;
			cin>>n;
			v.push_back(n);
		}
		else if (cmd=="pop"){
			if (v.empty()){
				cout<<-1<<endl;
			}
			else
			{
				cout<<v.front();
				v.erase(v.begin());
				cout<<endl;
			}
		}
		else if (cmd=="size"){
			cout<<v.size()<<endl;
		}
		else if (cmd=="empty"){
			if (v.empty())
				cout<<1<<endl;
			else
				cout<<0<<endl;}
		else if (cmd=="front"){
			if (v.empty())
				cout<<-1<<endl;
			else
				cout<<v.front()<<endl;
			}
		else if (cmd=="back"){
			if (v.empty())
				cout<<-1<<endl;
			else
				cout<<v.back()<<endl;
			}
		}
	return 0;	
}
