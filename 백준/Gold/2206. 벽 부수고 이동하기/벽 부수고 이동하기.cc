#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;
int arr[1000][1000];
int cost[1000][1000][2];
int n, m;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void BFS(){
    queue<iii> q;
    q.push(iii(ii(0, 0), 0));
    cost[0][0][0] = 1;
    while(!q.empty()){
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        int cur = cost[y][x][cnt];
        q.pop();
        for(int k=0; k<4; k++){
            if(y+dy[k]>=0 && y+dy[k]<n && x+dx[k]>=0 && x+dx[k]<m){
                if(arr[y+dy[k]][x+dx[k]] == 0){
                    if(cost[y+dy[k]][x+dx[k]][cnt]==0){
                        cost[y+dy[k]][x+dx[k]][cnt] = cur+1;
                        q.push(iii(ii(y+dy[k], x+dx[k]), cnt));
                    }
                }
                else if(arr[y+dy[k]][x+dx[k]] == 1 && cnt == 0){
                    if(cost[y+dy[k]][x+dx[k]][cnt+1]==0){
                        cost[y+dy[k]][x+dx[k]][cnt+1] = cur+1;
                        q.push(iii(ii(y+dy[k], x+dx[k]), cnt+1));
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
    for(int i=0; i<n; i++){
        string s; cin >> s;
        for(int j=0; j<m; j++){
            arr[i][j] = s[j]-'0';
        }
    }
    BFS();
    if(cost[n-1][m-1][0] == 0){
        if(cost[n-1][m-1][1] == 0)
            cout << -1 << '\n';
        else cout << cost[n-1][m-1][1] << '\n';
    }
    else{
        if(cost[n-1][m-1][1] == 0)
            cout << cost[n-1][m-1][0] << '\n';
        else cout << min(cost[n-1][m-1][0], cost[n-1][m-1][1]) << '\n';
    }
}