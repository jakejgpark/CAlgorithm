#include <iostream>
#include <vector>

#define MAX_N 20
#define MAX_M 5
#define DIR_NUM 4

using namespace std;

int n, m, k;
int board[MAX_N + 1][MAX_N + 1];

// 각 팀별 레일 위치를 관리합니다.
vector<pair<int, int> > v[MAX_M + 1];
// 각 팀별 tail 위치를 관리합니다.
int tail[MAX_M + 1];
bool visited[MAX_N + 1][MAX_N + 1];

// 격자 내 레일에 각 팀 번호를 적어줍니다.
int board_idx[MAX_N + 1][MAX_N + 1];

int ans;

int dx[DIR_NUM] = {-1, 0, 1, 0};
int dy[DIR_NUM] = {0, -1, 0, 1};

bool IsOutRange(int x, int y) {
    return !(1 <= x && x <= n && 1 <= y && y <= n);
}

// 초기 레일을 만들기 위해 dfs를 이용합니다.
void DFS(int x, int y, int idx) {
    visited[x][y] = true;
    board_idx[x][y] = idx;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(IsOutRange(nx, ny)) continue;

        // 이미 지나간 경로거나 경로가 아니면 넘어갑니다.
        if(board[nx][ny] == 0) continue;
        if(visited[nx][ny]) continue;

        // 가장 처음 탐색할 때 2가 있는 방향으로 dfs를 진행합니다.
        if((int) v[idx].size() == 1 && board[nx][ny] != 2) continue;

        v[idx].push_back({nx, ny});
        if(board[nx][ny] == 3) tail[idx] = (int) v[idx].size();
        DFS(nx, ny, idx);
    }
}

// 입력을 받는 등 초기 작업을 합니다.
void Init() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];

    int cnt = 1;

    // 레일을 벡터에 저장합니다. 머리사람을 우선 앞에 넣어줍니다.
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(board[i][j] == 1) v[cnt++].push_back({i, j});

    // dfs를 통해 레일을 벡터에 순서대로 넣어줍니다.
    for(int i = 1; i <= m; i++)
        DFS(v[i][0].first, v[i][0].second, i);
}

void print()
{
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			cout<<board[i][j];
		}
		cout<<endl;
	}
}

int main() {
	Init();
	print();

    return 0;
}
