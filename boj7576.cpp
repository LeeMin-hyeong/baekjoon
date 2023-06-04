#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int>p;
int n, m, arr[1000][1000];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};
bool visited[1000][1000];
queue<p> q;

void BFS(){
    int ans = 0;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int ny = y+dy[k];
            int nx = x+dx[k];
            if(ny>=0 && ny<n && nx>=0 && nx<m){
                if(arr[ny][nx] == 0){
                    if(!visited[ny][nx]){
                        visited[ny][nx] = true;
                        q.push(p(ny, nx));
                        arr[ny][nx] = arr[y][x] + 1;
                    }
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                q.push(p(i, j));
                visited[i][j] = true;
            }
        }
    }
    if(q.empty()){
        cout << -1 << '\n';
        return 0;
    }
    BFS();
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            ans = max(ans, arr[i][j]);
            if(arr[i][j] == 0){
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    cout << ans-1 << '\n';
}