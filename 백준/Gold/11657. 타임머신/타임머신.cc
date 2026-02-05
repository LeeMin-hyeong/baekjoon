#include <bits/stdc++.h>
#define INF 2500000001
using namespace std;

typedef pair<int, int> p;
vector<p> e[510];
long long dist[510];
int n, m;

bool bellman_ford(){
    dist[1] = 0;
    for(int i=0; i<n; i++){
        for(int j=1; j<510; j++){
            if(dist[j] == INF) continue;
            for(int k=0; k<e[j].size(); k++){
                int u = j;
                int v = e[j][k].first;
                int w = e[j][k].second;
                if(dist[v] > dist[u]+w){
                    dist[v] = dist[u]+w;
                    if(i == n-1) return false;
                }
            }
        }
    }
    return true;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back(p(v, w));
    }
    for(int i=1; i<510; i++){
        dist[i] = INF;
    }
    if(bellman_ford()){
        for(int i=2; i<=n; i++){
            if(dist[i] == INF) cout << -1 << '\n';
            else cout << dist[i] << '\n';
        }
    }
    else cout << "-1\n";
}