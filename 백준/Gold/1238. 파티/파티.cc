#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
vector<p> e[1001], be[1001];
int n, m, party, to_party[1001], from_party[1001];

void dijkstra(int x, vector<p> edge[], int dist[]){
    dist[x] = 0;
    priority_queue<p> pq;
    pq.push(p(0, x));
    while(!pq.empty()){
        int w = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(dist[u] < w) continue;
        for(int i=0; i<edge[u].size(); i++){
            if(dist[edge[u][i].first] > dist[u]+edge[u][i].second){
                dist[edge[u][i].first] = dist[u]+edge[u][i].second;
                pq.push(p(-dist[u]+edge[u][i].second, edge[u][i].first));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> party;
    for(int i=0; i<m; i++){
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back(p(v, w));
        be[v].push_back(p(u, w));
    }
    memset(to_party, 0x7f, sizeof(to_party));
    dijkstra(party, be, to_party);
    memset(from_party, 0x7f, sizeof(from_party));
    dijkstra(party, e, from_party);
    int ans = 0;
    for(int i=1; i<=n; i++){
        ans = max(ans, to_party[i]+from_party[i]);
    }
    cout << ans << '\n';
}