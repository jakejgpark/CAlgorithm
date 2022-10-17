#include <iostream>
#include <string>
using namespace std;


int main()
{
	char* arr;
	arr=(char*) malloc(10);
	cin.getline(arr, 10);
	
	cout<<arr;
	return 0;
}
