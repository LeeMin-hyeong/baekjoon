#include <bits/stdc++.h>
using namespace std;

char board[51][51];
bool visited[51][51];
int memo[51][51];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int n, m;

bool check_end(int y, int x){
    return y < 1 || x < 1 || y > n || x > m || board[y][x] == 'H';
}

int dfs(int y, int x){
    if(check_end(y, x)) return 0;
    if(visited[y][x]) return -1;
    if(memo[y][x] != -2) return memo[y][x];

    visited[y][x] = true;
    int best = 0;

    int jump = board[y][x] - '0';
    for(int i=0; i<4; i++){
        int ny = y + dy[i] * jump;
        int nx = x + dx[i] * jump;

        int ret = dfs(ny, nx);
        if(ret == -1){
            visited[y][x] = false;
            return -1;
        }

        best = max(best, ret + 1);
    }

    visited[y][x] = false;
    memo[y][x] = best;

    return best;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            memo[i][j] = -2;
    cout << dfs(1, 1) << '\n';
}
