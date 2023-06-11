#include <bits/stdc++.h>
using namespace std;

bool visited[51];
bool prime[2001];
int arr[51];
int parent[51];
vector<int> v[51], ans;
int n;

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
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i=2; i<2001; i++){
        for(int j=2; i*j<2001; j++){
            prime[i*j] = false;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) continue;
            if(prime[arr[i]+arr[j]]){
                v[i].push_back(j);
            }
        }
    }
    for(int i=0; i<v[1].size(); i++){
        bool wa = false;
        memset(parent, 0, sizeof(parent));
        parent[v[1][i]] = 1;
        for(int j=2; j<=n; j++){
            memset(visited, false, sizeof(visited));
            visited[1] = true;
            dfs(j);
        }
        for(int j=1; j<=n; j++){
            if(parent[j] == 0) wa = true;
        }
        if(wa) continue;
        ans.push_back(arr[v[1][i]]);
    }
    if(ans.size() == 0){
        cout << "-1\n";
        return 0;
    }
    sort(ans.begin(), ans.end());
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
}