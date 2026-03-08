#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int cost[10001];
int indegree[10001];
vector<int> edge[10001];
int dp[10001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=1; i<=n; i++){
        int t, k, p;
        cin >> t >> k;
        cost[i] = t;
        indegree[i] = k;
        for(int j=0; j<k; j++){
            cin >> p;
            edge[p].push_back(i);
        }
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
            dp[i] = cost[i];
        }
    }
    int ans = 0;
    while(!q.empty()){
        int cur = q.front();
        ans = cur;
        q.pop();
        for(int i=0; i<edge[cur].size(); i++){
            int next = edge[cur][i];
            indegree[next]--;
            dp[next] = max(dp[next], dp[cur] + cost[next]);
            if(indegree[next] == 0) q.push(next);
        }
    }
    cout << *max_element(dp+1, dp+n+1) << '\n';
}