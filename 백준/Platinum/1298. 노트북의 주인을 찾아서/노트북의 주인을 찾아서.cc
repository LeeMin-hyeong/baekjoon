#include <bits/stdc++.h>
using namespace std;

vector<int> v[101];
bool visited[101];
int parent[101];
int n, m;

bool dfs(int x){
    if(visited[x]) return false;
    visited[x] = true;
    for(int i=0; i<v[x].size(); i++){
        if(parent[v[x][i]]==0 || dfs(parent[v[x][i]])){
            parent[v[x][i]] = x;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        v[a].push_back(b);
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        memset(visited, false, sizeof(visited));
        if(dfs(i)) ans++;
    }
    cout << ans << '\n';
}