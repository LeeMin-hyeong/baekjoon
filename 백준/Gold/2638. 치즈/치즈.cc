#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int cheese[100][100];
bool air[100][100];
bool visited[100][100];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
queue<pair<int, int>> edges;

void bfs(int i, int j){
    visited[i][j] = true;
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        int cnt = 0;
        for(int k=0; k<4; k++){
            int ny = y+dy[k];
            int nx = x+dx[k];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(!visited[ny][nx] && cheese[ny][nx] == 1){
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
                if(cheese[ny][nx] == 0 && air[ny][nx]){
                    cnt++;
                }
            }
        }
        if(cnt >= 2){
            edges.push({y, x});
        }
    }
}

void check_air(){
    air[0][0] = true;
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int ny = y+dy[k];
            int nx = x+dx[k];
            if(ny >= 0 && ny < n && nx >= 0 && nx < m){
                if(!air[ny][nx] && cheese[ny][nx] == 0){
                    air[ny][nx] = true;
                    q.push({ny, nx});
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> cheese[i][j];
        }
    }
    int ans = 0;
    while(true){
        memset(air, false, sizeof(air));
        memset(visited, false, sizeof(visited));
        check_air();
        bool flag = true;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!visited[i][j] && cheese[i][j] == 1){
                    flag = false;
                    bfs(i, j);
                }
            }
        }
        if(flag) break;
        while(!edges.empty()){
            cheese[edges.front().first][edges.front().second] = 0;
            edges.pop();
        }
        ans++;
    }
    cout << ans << '\n';
}