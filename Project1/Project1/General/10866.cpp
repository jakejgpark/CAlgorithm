#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> v;
	int cnt;
	cin>>cnt;
	vector<int>::iterator it = v.begin();
	
	
	while (cnt--)
	{
		string cmd;
		int n=0;
		cin>>cmd;
		if (cmd=="push_front"){
			cin>>n;
			v.insert(v.begin(),n);
		}
		else if (cmd=="push_back"){
			cin>>n;
			v.emplace_back(n);
		}
		else if (cmd=="pop_front"){
			if(v.empty())
				cout<<-1<<endl;
			else{
				cout<<v.front()<<endl;
				v.erase(v.begin());
			}
		}
		else if (cmd=="pop_back"){
			if(v.empty())
				cout<<-1<<endl;
			else{
				cout<<v.back()<<endl;
				v.erase(v.end()-1);
			}	
		}
		else if (cmd=="size"){
				cout<<v.size()<<endl;
			}
		else if (cmd=="empty"){
			if(v.empty())
				cout<<1<<endl;
			else{
				cout<<0<<endl;
			}
		}
		else if (cmd=="front"){
			if(v.empty())
				cout<<-1<<endl;
			else{
				cout<<v.front()<<endl;
			}				
		}
		else if (cmd=="back"){
			if(v.empty())
				cout<<-1<<endl;
			else{
				cout<<v.back()<<endl;
			}
		}
	}
	
//	vector<int>::iterator iter;
//	for(iter=v.begin(); iter!=v.end(); iter++)
//	{
//		cout<<"Iterator: "<< *iter<<endl;
//	}
	
	return 0;	
}
