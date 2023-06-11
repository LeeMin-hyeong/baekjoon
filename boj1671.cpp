#include <bits/stdc++.h>
using namespace std;

int parent[51];
bool visited[51], eaten[51];
int shark[51][3];
vector<int> v[51];
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
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> shark[i][0] >> shark[i][1] >> shark[i][2];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(shark[i][0]==shark[j][0] && shark[i][1]==shark[j][1] && shark[i][2]==shark[j][2]){
                if(i<j) v[i].push_back(j);
            }
            else if(shark[i][0]>=shark[j][0] && shark[i][1]>=shark[j][1] && shark[i][2]>=shark[j][2]){
                v[i].push_back(j);
            }
        }
    }

    int cnt = 0;
    for(int i=1; i<=n; i++){
        memset(visited, false, sizeof(visited));
        if(dfs(i)) cnt++;
        memset(visited, false, sizeof(visited));
        if(dfs(i)) cnt++;
    }
    cout << n-cnt << '\n';
}