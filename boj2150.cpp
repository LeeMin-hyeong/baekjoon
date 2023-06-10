#include <bits/stdc++.h>
using namespace std;

vector<int> E[10001], RE[10001], ans[10001];
stack<int> s;
bool visited[10001];
int n, m;

bool comp(vector<int> a, vector<int> b){
    return a[0] < b[0];
}

void dfs(int x){
    for(int i=0; i<E[x].size(); i++){
        if(!visited[E[x][i]]){
            visited[E[x][i]] = true;
            dfs(E[x][i]);
        }
    }
    s.push(x);
}

void rdfs(int x, int cnt){
    for(int i=0; i<RE[x].size(); i++){
        if(!visited[RE[x][i]]){
            visited[RE[x][i]] = true;
            rdfs(RE[x][i], cnt);
        }
    }
    ans[cnt].push_back(x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        E[a].push_back(b);
        RE[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(i);
        }
    }
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    while(!s.empty()){
        int x = s.top(); s.pop();
        if(!visited[x]){
            visited[x] = true;
            rdfs(x, cnt++);
        }
    }
    for(int i=0; i<cnt; i++){
        sort(ans[i].begin(), ans[i].end());
    }
    sort(ans, ans+cnt, comp);
    cout << cnt << '\n';
    for(int i=0; i<cnt; i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << ' ';
        }
        cout << "-1\n";
    }
}