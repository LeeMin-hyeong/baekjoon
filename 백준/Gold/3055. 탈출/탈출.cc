#include <iostream>
#include <queue>
using namespace std;

int r, c, cnt;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char forest[50][50];
int memo[50][50];
pair<int, int> d;
queue<pair<int, int>> water, hedgehog;

void hedgehog_move(){
    int n = hedgehog.size();
    while(n--){
        int y = hedgehog.front().first;
        int x = hedgehog.front().second;
        hedgehog.pop();
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if(forest[ny][nx] == 'X') continue;
            if(memo[ny][nx] == -2) continue;
            if(memo[ny][nx] >= 0) continue;
            hedgehog.push({ny, nx});
            memo[ny][nx] = cnt+1;
        }
    }
    cnt++;
}

void water_move(){
    int n = water.size();
    while(n--){
        int y = water.front().first;
        int x = water.front().second;
        water.pop();
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
            if(forest[ny][nx] == 'X') continue;
            if(forest[ny][nx] == 'D') continue;
            if(memo[ny][nx] == -2) continue;
            water.push({ny, nx});
            memo[ny][nx] = memo[y][x];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            memo[i][j] = -1;
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> forest[i][j];
            if(forest[i][j] == 'S'){
                hedgehog.push({i, j});
                memo[i][j] = 0;
            }
            else if(forest[i][j] == 'D'){
                d = {i, j};
            }
            else if(forest[i][j] == '*'){
                water.push({i, j});
                memo[i][j] = -2;
            }
        }
    }
    while(!hedgehog.empty()){
        water_move();
        hedgehog_move();
        if(memo[d.first][d.second] > 0) break;
    }
    if(memo[d.first][d.second] == -1){
        cout << "KAKTUS\n";
    }
    else{
        cout << memo[d.first][d.second] << '\n';
    }
}
