#include <bits/stdc++.h>
using namespace std;

vector<int> e[100001];
stack<int> s;
bool visited[100001];
int n, m;

void dfs(int k){
    for(int i=0; i<e[k].size(); i++){
        if(!visited[e[k][i]]){
            visited[e[k][i]] = true;
            dfs(e[k][i]);
        }
    }
    s.push(k);
}

void dfs2(int k){
    for(int i=0; i<e[k].size(); i++){
        if(!visited[e[k][i]]){
            visited[e[k][i]] = true;
            dfs2(e[k][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(int i=0; i<m; i++){
            int x, y; cin >> x >> y;
            e[x].push_back(y);
        }
        memset(visited, false, sizeof(visited));
        for(int i=1; i<=n; i++){
            if(!visited[i]){
                visited[i] = true;
                dfs(i);
            }
        }
        int ans = 0;
        memset(visited, false, sizeof(visited));
        while(!s.empty()){
            int i = s.top(); s.pop();
            if(!visited[i]){
                visited[i] = true;
                dfs2(i);
                ans++;
            }
        }
        cout << ans << '\n';
        for(int i=1; i<=n; i++){
            e[i].clear();
        }
    }
}