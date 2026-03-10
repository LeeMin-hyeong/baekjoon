#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

int n, ans, far;
vector<pair<int, int>> edge[100001];
bool visited[100001];

void dfs(int cur, int dist){
    if(ans < dist){
        far = cur;
        ans = dist;
    }
    for(int i=0; i<edge[cur].size(); i++){
        int next = edge[cur][i].first;
        int w = edge[cur][i].second;
        if(!visited[next]){
            visited[next] = true;
            dfs(next, dist+w);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        int node; cin >> node;
        while(true){
            int a, b;
            cin >> a;
            if(a == -1) break;
            cin >> b;
            edge[node].push_back({a, b});
        }
    }
    visited[1] = true;
    dfs(1, 0);
    memset(visited, false, sizeof(visited));
    visited[far] = true;
    ans = 0;
    dfs(far, 0);
    cout << ans << '\n';
}