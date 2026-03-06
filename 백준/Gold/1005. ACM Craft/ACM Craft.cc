#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int t, n, k, x, y, w, d;

int cost[1001];
int indegree[1001];
vector<int> edge[1001];
int dp[1001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--){
        int ans = 0;
        memset(cost, 0, sizeof(cost));
        memset(indegree, 0, sizeof(indegree));
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<1001; i++){
            edge[i].clear();
        }
        cin >> n >> k;
        for(int i=1; i<=n; i++){
            cin >> cost[i];
        }
        for(int i=1; i<=k; i++){
            int x, y;
            cin >> x >> y;
            edge[x].push_back(y);
            indegree[y]++;
        }
        cin >> w;
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
                dp[edge[cur][i]] = max(dp[edge[cur][i]], dp[cur] + cost[edge[cur][i]]);
                indegree[edge[cur][i]]--;
                if(indegree[edge[cur][i]] == 0){
                    q.push(edge[cur][i]);
                }
            }
        }
        cout << dp[w] << '\n';
    }
}