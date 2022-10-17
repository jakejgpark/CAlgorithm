#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
//	/* string to int */
//	int num=10;
//	string str;
//	str=to_string(num);
//	cout<<str;
	
	/* int to string */
	string str="1234";
	int num=0;
	num=stoi(str,nullptr,16);
	cout<<num;
	


	return 0;	
}
