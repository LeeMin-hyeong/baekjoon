#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int indegree[101];
int part[101][101];
int dp[101][101];
bool basic[101];
vector<int> edge[101];
queue<int> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x, y, k;
        cin >> x >> y >> k;
        indegree[x]++;
        edge[y].push_back(x);
        part[x][y] = k;
    }
    for(int i=1; i<=n; i++){
        if(indegree[i] == 0){
            q.push(i);
            dp[i][i] = 1;
            basic[i] = true;
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<edge[cur].size(); i++){
            int next = edge[cur][i];
            for(int j=1; j<=n; j++){
                dp[next][j] += dp[cur][j] * part[next][cur];
            }
            indegree[next]--;
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }
    for(int i=1; i<=n; i++){
        if(basic[i]){
            cout << i << ' ' << dp[n][i] << '\n';
        }
    }
}
