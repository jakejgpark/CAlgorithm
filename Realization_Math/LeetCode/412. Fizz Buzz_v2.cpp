#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> fizzBuzz;

void Solution {
		int n=5;
        vector<string> res(n);
        
        for (int i=1; i<n; i++)
        {
        	res[i-1]=to_string(i);
        }

        for (int i=2; i<n; i+=3)
        {
        	res[i]="Fizz";
        }
        
        for (int i=4; i<n; i+=5)
        {
        	res[i]="Buzz";
        }
        
        for (int i = 14; i<n; i+=15)
        {
        	res[i]="FizzBuzz";
        }
        return res;
    }
};

int main()
{
	Solution();
	for (int i=0; i<fizzBuzz.size(); i++)
	{
		cout<<fizzBuzz[i]<<" ";
	}
	
	return 0;
}
