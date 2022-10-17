#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int n=0;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

typedef struct {
	int x;
	int y;
} coord;

void dfs(int x, int y, int cnt){
	if (x<0||y<||x>=n||y>=n){
		return;
	}
	
	for (int i=0; i<4; i++){
		int nx = x + dx[i];
	

int main(void)
{
	scanf("%d", &n);
	int n_square = n*n;
	int n_sqaure_copy = n_square;
	int arr[n_square][5]={0,};
	int graph[n][n]={0,};
	int score1[n][n][n_square]={0,};
	int score2[n][n][n_square]={0,};
	int score3[n][n][n_square]={0,};
	
	for (int i=0; i<n_square; i++)
	{
		for (int j=0; j<5; j++){
			scanf("%d", &arr[i][j]);
//			printf("%d ", arr[n_square][j]);
		}
	}
	
	while (n_square_copy--)
	{
		for (int k=0; k<n_square; k++){
			for (int i=0; i<n; i++){
				for (int j=0; j<n; j++){
					
					
	
	
//	for (int i=0; i<n_square; i++)
//	{
//		for (int j=0; j<5; j++){
//			printf("%d", arr[i][j]);
//		}
//		printf("\n");
//	}
	
	
	return 0;
}
