#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int n = 8;
char maze[8][8];
vector<pair<int, int>> wall;
queue<pair<int, int>> ukje;
bool visited[8][8];
int dy[] = {-1, 0, 1, 0, -1, -1, 1, 1, 0};
int dx[] = {0, 1, 0, -1, -1, 1, -1, 1, 0};

void ukje_move(){
    int s = ukje.size();
    while(s--){
        int y = ukje.front().first;
        int x = ukje.front().second;
        ukje.pop();

        if(maze[y][x] == '#') continue;

        for(int i=0; i<9; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if(maze[ny][nx] == '#') continue;
            if(visited[ny][nx]) continue;

            visited[ny][nx] = true;
            ukje.push({ny, nx});
        }
    }
}

void wall_move(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            maze[i][j] = '.';
        }
    }

    vector<pair<int, int>> new_wall;
    for(int i=0; i<(int)wall.size(); i++){
        int y = wall[i].first + 1;
        int x = wall[i].second;
        if(y < n){
            new_wall.push_back({y, x});
            maze[y][x] = '#';
        }
    }
    wall = new_wall;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> maze[i][j];
            if(maze[i][j] == '#'){
                wall.push_back({i, j});
            }
        }
    }

    ukje.push({7, 0});

    while(!ukje.empty()){
        memset(visited, false, sizeof(visited));
        ukje_move();

        if(ukje.empty()) break;
        if(visited[0][7]){
            cout << 1 << '\n';
            return 0;
        }

        wall_move();
    }

    cout << 0 << '\n';
}