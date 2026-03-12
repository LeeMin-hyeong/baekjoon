#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int dp[501];
int indegree[501];
int cost[501];
vector<int> edge[501];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> cost[i];
        while(true){
            int a; cin >> a;
            if(a == -1) break;
            indegree[i]++;
            edge[a].push_back(i);
        }
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
            dp[i] = cost[i];
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<edge[cur].size(); i++){
            int next = edge[cur][i];
            indegree[next]--;
            dp[next] = max(dp[next], dp[cur] + cost[next]);
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }
    for(int i=1; i<=n; i++){
        cout << dp[i] << '\n';
    }
}