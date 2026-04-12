#include <iostream>
#include <queue>
using namespace std;

int r, c, cnt;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
char forest[50][50];
bool visited[50][50];
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
            if(visited[ny][nx]) continue;
            hedgehog.push({ny, nx});
            visited[ny][nx] = true;
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
            if(visited[ny][nx]) continue;
            water.push({ny, nx});
            visited[ny][nx] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> forest[i][j];
            if(forest[i][j] == 'S'){
                hedgehog.push({i, j});
                visited[i][j] = true;
            }
            else if(forest[i][j] == 'D'){
                d = {i, j};
            }
            else if(forest[i][j] == '*'){
                water.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    while(!hedgehog.empty()){
        water_move();
        hedgehog_move();
        if(visited[d.first][d.second]) break;
    }
    if(!visited[d.first][d.second]){
        cout << "KAKTUS\n";
    }
    else{
        cout << cnt << '\n';
    }
}
