#include <bits/stdc++.h>
using namespace std;

int n, m;
int parent[50001];
int depth[50001];
vector<int> child[50001];
bool visited[50001];

void dfs(int c, int p){
    visited[c] = true;
    parent[c] = p;
    for(int nxt : child[c]){
        if(!visited[nxt]){
            depth[nxt] = depth[c] + 1;
            dfs(nxt, c);
        }
    }
}

int lca(int a, int b){
    while(depth[a] > depth[b]) a = parent[a];
    while(depth[b] > depth[a]) b = parent[b];
    while(a != b){
        a = parent[a];
        b = parent[b];
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        child[a].push_back(b);
        child[b].push_back(a);
    }

    dfs(1, 0);

    cin >> m;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}