#include <bits/stdc++.h>
using namespace std;

int n, m, parent[201];
bool visited[201];
vector<int> v[201];

bool dfs(int k){
    if(visited[k]) return false;
    visited[k] = true;
    for(int i=0; i<v[k].size(); i++){
        if(parent[v[k][i]] == 0 || dfs(parent[v[k][i]])){
            parent[v[k][i]] = k;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        int s; cin >> s;
        for(int j=0; j<s; j++){
            int x; cin >> x;
            v[i].push_back(x);
        }
    }
    int ans = 0;
    for(int i=1; i<=n; i++){
        memset(visited, false, sizeof(visited));
        if(dfs(i)) ans++;
    }
    cout << ans << '\n';
}
