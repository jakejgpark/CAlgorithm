#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> fizzBuzz;

void solution()
{
	int n=5;
	
	for (int i=1; i<=n; i++)
	{
		if (i%3==0 && i%5==0)
		{
			fizzBuzz.push_back({"FizzBuzz"});
		}
		else if (i%3==0)
		{
			fizzBuzz.push_back({"Fizz"});
		}
		else if (i%5==0)
		{
			fizzBuzz.push_back({"Buzz"});
		}
		else
		{
			fizzBuzz.push_back({to_string(48+i)});
		}
	}
}

int main()
{
	solution();
	cout<<fizzBuzz[12];
	return 0;
}
