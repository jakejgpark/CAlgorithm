#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

#define MAX_T 25
#define MAX_N 4
#define DIR_NUM 8
#define P_DIR_NUM 4
#define MAX_DECAY 2

using namespace std;

int switch_dir(int x)
{
	switch (x){
	case 1:
		return 1;
	case 2:
		return 2;
	case 3:
		return 3;
		}
}
	


int test(int(*arr)[3])
{
	cout<<arr[0][0];
	return 0;
}

int main()
{
	int arr[3][3]={1,};
	cout<<switch_dir(3);
	return 0;
}
