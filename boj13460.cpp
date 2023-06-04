#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
int n, m;
char arr[10][10];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

int rmove[10][10];
int bmove[10][10];
bool rvisited[10][10];
bool bvisited[10][10];
queue<p> q;

int BFS(){
    int cnt = 1;
    while(!q.empty()){
        int ry = q.front().first;
        int rx = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            while(arr[ry][rx] != '#'){
                int ry = ry+dy[k];
                int rx = rx+dx[k];
            }
        }
        cnt++;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    p rl, bl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'R') rl = p(i, j);
            if(arr[i][j] == 'B') bl = p(i, j);
        }
    }
    q.push(rl);
    // q.push(bl);
    cout << BFS();
}