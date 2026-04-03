#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <deque>
using namespace std;

int n, m, ret = 1'000'000'000, ans;
bool edge[101][101], visited[101];

int bfs(int x){
    int ret = 0;
    visited[x] = true;
    queue<pair<int, int>> q;
    q.push({x, 0});
    while(!q.empty()){
        int cur = q.front().first;
        int step = q.front().second;
        q.pop();
        ret += step;
        for(int i=1; i<=n; i++){
            if(visited[i]) continue;
            if(!edge[cur][i]) continue;
            visited[i] = true;
            q.push({i, step+1});
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        edge[a][b] = true;
        edge[b][a] = true;
    }
    for(int i=1; i<=n; i++){
        memset(visited, false, sizeof(visited));
        int r = bfs(i);
        if(ret > r){
            ret = r;
            ans = i;
        }
    }
    cout << ans << '\n';
}