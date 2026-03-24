#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> edge[1001];
bool visited[1001];

void dfs(int u){
    for(int i=0; i<edge[u].size(); i++){
        int v = edge[u][i];
        if(!visited[v]){
            visited[v] = true;
            dfs(v);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(i);
            ans++;
        }
    }
    cout << ans << '\n';
}