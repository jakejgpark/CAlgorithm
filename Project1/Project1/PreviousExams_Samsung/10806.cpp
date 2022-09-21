#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n=0;
int n_square=0;

struct coord{
	int x;
	int y;
} point;

int main()
{
	scanf("%d", &n);
	n_square=n*n;
	int graph[n][n]={0,};
	int score[n][n]={0,};
	
	
	int arr_score[n_square][5]={0,};
	for (int i=0; i<n_square; i++){
		for (int j=0; j<5; j++){
			scanf("%d", &arr_score[i][j]);
		}
	}	
//	for (int i=0; i<n_square; i++){
//		for (int j=0; j<5; j++){
//			printf("%d", arr_score[i][j]);
//		}
//		printf("\n");
//	}
	
	
	
	return 0;	
}
