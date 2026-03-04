#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int cheese[100][100];
bool visited[100][100];
int contact[100][100];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
queue<pair<int, int>> edges;

bool check_air(){
    visited[0][0] = true;
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
                if(!visited[ny][nx] && cheese[ny][nx] == 0){
                    visited[ny][nx] = true;
                    q.push({ny, nx});
                }
                if(cheese[ny][nx] == 1){
                    contact[ny][nx] += 1;
                    if(contact[ny][nx] >= 2 && !visited[ny][nx]){
                        edges.push({ny, nx});
                        visited[ny][nx] = true;
                    }
                }
            }
        }
    }
    return edges.empty();
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
        memset(visited, false, sizeof(visited));
        memset(contact, 0, sizeof(contact));
        check_air();
        if(check_air()) break;
        while(!edges.empty()){
            cheese[edges.front().first][edges.front().second] = 0;
            edges.pop();
        }
        ans++;
    }
    cout << ans << '\n';
}