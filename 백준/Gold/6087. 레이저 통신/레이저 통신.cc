#include <iostream>
#include <deque>
#include <tuple>
using namespace std;

int w, h;
char m[100][100];
int memo[100][100][4];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
pair<int, int> p[2];

void bfs(){
    deque<tuple<int, int, int>> dq;

    for(int i=0; i<4; i++){
        int ny = p[0].first + dy[i];
        int nx = p[0].second + dx[i];
        if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
        if(m[ny][nx] == '*') continue;
        memo[ny][nx][i] = 0;
        dq.push_back({ny, nx, i});
    }

    while(!dq.empty()){
        int y = get<0>(dq.front());
        int x = get<1>(dq.front());
        int d = get<2>(dq.front());
        dq.pop_front();

        int c = memo[y][x][d];

        for(int i=0; i<4; i++){
            if(i == (d + 2) % 4) continue;

            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if(m[ny][nx] == '*') continue;

            int nc = c + (i != d);

            if(memo[ny][nx][i] <= nc) continue;
            memo[ny][nx][i] = nc;

            if(i == d) dq.push_front({ny, nx, i});
            else dq.push_back({ny, nx, i});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h;
    int k = 0;
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin >> m[i][j];
            if(m[i][j] == 'C'){
                p[k++] = {i, j};
            }
            for(int d=0; d<4; d++){
                memo[i][j][d] = 1e9;
            }
        }
    }

    bfs();

    int ans = 1e9;
    for(int i=0; i<4; i++){
        ans = min(ans, memo[p[1].first][p[1].second][i]);
    }
    cout << ans << '\n';
}