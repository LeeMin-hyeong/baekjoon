#include <bits/stdc++.h>
using namespace std;

bool visited[26];
char arr[20][20];
int r, c, ans = 0;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void dfs(int i, int j, int cnt){
    for(int k=0; k<4; k++){
        int y = i+dy[k];
        int x = j+dx[k];
        if(y>=0 && y<r && x>=0 && x<c){
            if(!visited[arr[y][x]-'A']){
                visited[arr[y][x]-'A'] = true;
                dfs(y, x, cnt+1);
                visited[arr[y][x]-'A'] = false;
            }
        }
    }
    ans = max(ans, cnt);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> arr[i][j];
        }
    }
    visited[arr[0][0]-'A'] = true;
    dfs(0, 0, 1);
    cout << ans << '\n';
}