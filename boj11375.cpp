#include <bits/stdc++.h>
using namespace std;

int parent[1001];
bool visited[1001];
vector<int> v[1001];
int n, m, k, ans;

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
    cin >> n >> m >> k;
    for(int i=1; i<=n; i++){
        int a; cin >> a;
        for(int j=0; j<a; j++){
            int x; cin >> x;
            v[i].push_back(x);
        }
    }

    for(int i=1; i<=n; i++){
        memset(visited, false, sizeof(visited));
        if(dfs(i)) ans++;
    }
    while(true){
        bool task = false;
        for(int i=1; i<=n; i++){
            memset(visited, false, sizeof(visited));
            if(dfs(i) && k){
                k--;
                ans++;
                task = true;
            }
        }
        if(!task) break;
    }

    cout << ans << '\n';
}