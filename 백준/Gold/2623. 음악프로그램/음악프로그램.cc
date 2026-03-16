#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int indegree[1001];
queue<int> q, ans;
vector<int> edge[1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a; cin >> a;
        int prev;
        for(int j=0; j<a; j++){
            int b; cin >> b;
            if(j > 0){
                edge[prev].push_back(b);
                indegree[b]++;
            }
            prev = b;
        }
    }
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        ans.push(cur);
        for(int i=0; i<edge[cur].size(); i++){
            int next = edge[cur][i];
            indegree[next]--;
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }
    if(ans.size() != n){
        cout << 0 << '\n';
    }
    else{
        while(!ans.empty()){
            cout << ans.front() << '\n';
            ans.pop();
        }
    }
}