#include <bits/stdc++.h>
using namespace std;

bool visited[32001];
vector<int> e[32001], be[32001];
stack<int> s;
int n, m;

void dfs(int a){
    visited[a] = true;
    for(int i=0; i<e[a].size(); i++){
        if(!visited[e[a][i]]){
            dfs(e[a][i]);
        }
    }
    s.push(a);
}

void rdfs(int a){
    visited[a] = true;
    cout << a << ' ';
    for(int i=0; i<be[a].size(); i++){
        if(!visited[be[a][i]]){
            dfs(be[a][i]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        e[a].push_back(b);
        be[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    memset(visited, false, sizeof(visited));
    while(!s.empty()){
        int a = s.top(); s.pop();
        if(!visited[a]){
            rdfs(a);
        }
    }
    cout << '\n';
}