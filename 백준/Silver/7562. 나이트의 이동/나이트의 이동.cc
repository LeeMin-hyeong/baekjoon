#include <bits/stdc++.h>
using namespace std;

int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
int board[300][300];

void print_board(int l){
    for(int i=0; i<l; i++){
        for(int j=0; j<l; j++){
            cout << board[i][j] << ' ';
        }
        cout << '\n';
    }
}

int bfs(int l, int cy, int cx, int ty, int tx){
    memset(board, -1, sizeof(board));
    queue<pair<int, int>> q;
    board[cy][cx] = 0;
    q.push({cy, cx});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if(y == ty && x == tx) break;;
        for(int i=0; i<8; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny >= 0 && ny < l && nx >= 0 && nx <l){
                if(board[ny][nx] == -1){
                    q.push({ny, nx});
                    board[ny][nx] = board[y][x]+1;
                }
            }
        }
    }
    return board[ty][tx];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--){
        int l; cin >> l;
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << bfs(l, a, b, c, d) << '\n';
    }
}