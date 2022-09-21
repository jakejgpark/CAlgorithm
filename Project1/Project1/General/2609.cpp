#include <iostream>
#include <vector>
#include <algorithm>
#define MIN(a,b) (((a)>(b))? (a):(b))
using namespace std;

int main()
{
	int a=0;
	int b=0;
	int max=-2147000000;
	int min=2147000000;
	scanf("%d %d", &a, &b);
	vector<int> num_a;
	vector<int> num_b;
	
	for (int i=1; i<=a; i++)
	{
		if (a%i==0){
			num_a.emplace_back(i);
		}
	}
	
	for (int i=1; i<=b; i++)
	{
		if (b%i==0){
			num_b.emplace_back(i);
		}
	}
	
//	for (int i=0; i<num_a.size(); i++)
//	{
//		printf("%d\n", num_a[i]);
//	}
//	
//	for (int i=0; i<num_b.size(); i++)
//	{
//		printf("%d\n", num_b[i]);
//	}

	for (int i=0; i<num_a.size(); i++)
	{
		if (find(num_b.begin(), num_b.end(), num_a[i])!=num_b.end())
		{
//			cout<<num_a[i]<<" "<<"not exist";
			max=num_a[i];
		}
	}
	
	cout<<max<<"\n";
	int copy_a=a;
	while (1)
	{
		if (copy_a%b==0)
		{
			cout<<copy_a;
			break;
		}
		copy_a+=a;
	}
	
	return 0;	
}
