#include <bits/stdc++.h>
using namespace std;

int parent[1001];
bool visited[1001];
vector<int> v[1001];
int n, m, ans;

bool dfs(int k){
    if(visited[k]) return false;
    visited[k] = true;
    for(int i=0; i<v[k].size(); i++){
        if(parent[v[k][i]]==0 || dfs(parent[v[k][i]])){
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
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }

    for(int i=1; i<=n; i++){
        memset(visited, false, sizeof(visited));
        if(dfs(i)) ans++;
    }
    cout << ans << '\n';
}