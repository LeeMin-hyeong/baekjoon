#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int n, m;
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
char maze[51][51];
bool visited[51][51][1<<6];
int memo[51][51][1<<6];
vector<pair<int, int>> maze_exit;
queue<tuple<int, int, int>> q;

bool is_key(char c){
    return c >= 'a' && c <= 'f';
}

bool is_door(char c){
    return c >= 'A' && c <= 'F';
}

bool has_key(char c, int k){
    return k & (1<<(c-'A'));
}

int add_key(char c, int k){
    return k | (1<<(c-'a'));
}

void escape(){
    while(!q.empty()){
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int k = get<2>(q.front());
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny >= 0 && ny < n && nx >=0 && nx < m){
                if(maze[ny][nx] == '#') continue;
                if(is_key(maze[ny][nx])){
                    int nk = add_key(maze[ny][nx], k);
                    if(!visited[ny][nx][nk]){
                        q.push({ny, nx, nk});
                        memo[ny][nx][nk] = memo[y][x][k]+1;
                        visited[ny][nx][nk] = true;
                    }
                }
                else{
                    if(!visited[ny][nx][k]){
                        if(is_door(maze[ny][nx]) && has_key(maze[ny][nx], k)){
                            q.push({ny, nx, k});
                            memo[ny][nx][k] = memo[y][x][k]+1;
                            visited[ny][nx][k] = true;
                        }
                        else if(maze[ny][nx] == '1' || maze[ny][nx] == '.' || maze[ny][nx] == '0'){
                            q.push({ny, nx, k});
                            memo[ny][nx][k] = memo[y][x][k]+1;
                            visited[ny][nx][k] = true;
                        }
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    pair<int, int> p;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<1<<6; k++){
                memo[i][j][k] = 1e9;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> maze[i][j];
            if(maze[i][j] == '0'){
                q.push({i, j, 0});
                visited[i][j][0] = true;
                memo[i][j][0] = 0;
            }
            if(maze[i][j] == '1'){
                maze_exit.push_back({i, j});
            }
        }
    }
    escape();

    int ans = 1e9;
    for(int i=0; i<maze_exit.size(); i++){
        for(int j=0; j<1<<6; j++){
            ans = min(ans, memo[maze_exit[i].first][maze_exit[i].second][j]);
        }
    }
    if(ans == 1e9){
        cout << -1 << '\n';
    }
    else{
        cout << ans << '\n';
    }
}