#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
int edge[801][801];
int cost[801];
int n, e, v1, v2;

long long dijkstra(int from, int to){
    for(int i=1; i<801; i++){
        cost[i] = 1e9;
    }
    cost[from] = 0;
    priority_queue<p> pq;
    pq.push(p(0, from));
    while(!pq.empty()){
        int w = -pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if(w > cost[v]) continue;

        for(int i=1; i<=n; i++){
            if(i == v) continue;;
            if(edge[v][i] == -1) continue;
            if(cost[i] > cost[v]+edge[v][i]){
                cost[i] = cost[v]+edge[v][i];
                pq.push(p(-(cost[v]+edge[v][i]), i));
            }
        }
    }

    if(cost[to] == 1e9){
        return 1e9;
    }
    else{
        return cost[to];
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(edge, -1, sizeof(edge));
    cin >> n >> e;
    for(int i=0; i<e; i++){
        int a, b, c;
        cin >> a >> b >> c;
        edge[a][b] = c;
        edge[b][a] = c;
    }
    cin >> v1 >> v2;
    
    long long ret1 = dijkstra(1,v1)+dijkstra(v1,v2)+dijkstra(v2,n);
    long long ret2 = dijkstra(1,v2)+dijkstra(v2,v1)+dijkstra(v1,n);
    long long ans = min(ret1, ret2);
    if(ans >= 1e9){
        cout << -1 << '\n';
    }
    else{
        cout << ans << '\n';
    }
}