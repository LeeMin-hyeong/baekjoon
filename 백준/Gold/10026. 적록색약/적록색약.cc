#include <bits/stdc++.h>
using namespace std;

bool visited[100][100];
char arr[100][100];
int n;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void dfs(int i, int j){
    char cur = arr[i][j];
    for(int k=0; k<4; k++){
        int y = i+dy[k];
        int x = j+dx[k];
        if(y>=0 && y<n && x>=0 && x<n){
            if(arr[y][x] == cur){
                if(!visited[y][x]){
                    visited[y][x] = true;
                    dfs(y, x);
                }
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    int cnt1 = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                visited[i][j] = true;
                dfs(i, j);
                cnt1++;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[i][j] == 'R')
                arr[i][j] = 'G';
        }
    }
    memset(visited, false, sizeof(visited));
    int cnt2 = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(!visited[i][j]){
                visited[i][j] = true;
                dfs(i, j);
                cnt2++;
            }
        }
    }
    cout << cnt1 << ' ' << cnt2 << '\n';
}