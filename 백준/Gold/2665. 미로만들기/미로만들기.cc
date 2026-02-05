#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
bool room[50][50];
int visited[50][50];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int n;

void bfs(){
    queue<p> q;
    q.push(p(0, 0));
    visited[0][0] = 0;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int ny = y+dy[k];
            int nx = x+dx[k];
            if(ny>=0 && ny<n && nx>=0 && nx<n){
                if(room[ny][nx]){
                    if(visited[ny][nx] > visited[y][x]){
                        visited[ny][nx] = visited[y][x];
                        q.push(p(ny, nx));
                    }
                }
                else{
                    if(visited[ny][nx] > visited[y][x]+1){
                        visited[ny][nx] = visited[y][x]+1;
                        q.push(p(ny, nx));
                    }
                }
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<n; j++){
            if(s[j] == '1')
                room[i][j] = true;
            else
                room[i][j] = false;
        }
    }
    memset(visited, 0x7f, sizeof(visited));
    bfs();
    cout << visited[n-1][n-1] << '\n';
}