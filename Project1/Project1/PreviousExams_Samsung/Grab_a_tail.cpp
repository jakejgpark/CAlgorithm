#include <iostream>
#include <vector>

#define MAX_N 20
#define MAX_M 5
#define DIR_NUM 4

using namespace std;

int n, m, k;
int board[MAX_N + 1][MAX_N + 1];

// �� ���� ���� ��ġ�� �����մϴ�.
vector<pair<int, int> > v[MAX_M + 1];
// �� ���� tail ��ġ�� �����մϴ�.
int tail[MAX_M + 1];
bool visited[MAX_N + 1][MAX_N + 1];

// ���� �� ���Ͽ� �� �� ��ȣ�� �����ݴϴ�.
int board_idx[MAX_N + 1][MAX_N + 1];

int ans;

int dx[DIR_NUM] = {-1, 0, 1, 0};
int dy[DIR_NUM] = {0, -1, 0, 1};

bool IsOutRange(int x, int y) {
    return !(1 <= x && x <= n && 1 <= y && y <= n);
}

// �ʱ� ������ ����� ���� dfs�� �̿��մϴ�.
void DFS(int x, int y, int idx) {
    visited[x][y] = true;
    board_idx[x][y] = idx;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(IsOutRange(nx, ny)) continue;

        // �̹� ������ ��ΰų� ��ΰ� �ƴϸ� �Ѿ�ϴ�.
        if(board[nx][ny] == 0) continue;
        if(visited[nx][ny]) continue;

        // ���� ó�� Ž���� �� 2�� �ִ� �������� dfs�� �����մϴ�.
        if((int) v[idx].size() == 1 && board[nx][ny] != 2) continue;

        v[idx].push_back({nx, ny});
        if(board[nx][ny] == 3) tail[idx] = (int) v[idx].size();
        DFS(nx, ny, idx);
    }
}

// �Է��� �޴� �� �ʱ� �۾��� �մϴ�.
void Init() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> board[i][j];

    int cnt = 1;

    // ������ ���Ϳ� �����մϴ�. �Ӹ������ �켱 �տ� �־��ݴϴ�.
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(board[i][j] == 1) v[cnt++].push_back({i, j});

    // dfs�� ���� ������ ���Ϳ� ������� �־��ݴϴ�.
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
