#include <bits/stdc++.h>
#define INF 10000000000
using namespace std;

typedef pair<int, int> p;
vector<p> edge[50];
queue<int> c;
bool visited[50];
int pay[50];
long long dist[50];
int n, s, e, m;

bool bfs(){
    while(!c.empty()){
        int u = c.front(); c.pop();
        for(int i=0; i<edge[u].size(); i++){
            int v = edge[u][i].first;
            if(visited[v]) continue;
            visited[v] = true;
            c.push(v);
        }
    }
    return visited[e];
}

void bellman_ford(){
    dist[s] = pay[s];
    for(int i=0; i<n; i++){
        for(int j=0; j<50; j++){
            if(dist[j] == -INF) continue;
            for(int k=0; k<edge[j].size(); k++){
                int u = j;
                int v = edge[j][k].first;
                int w = pay[v] - edge[j][k].second;
                if(dist[u]+w > dist[v]){
                    dist[v] = dist[u]+w;
                    if(i == n-1) c.push(u);
                }
            }
        }
    }
}

int main(){
    cin >> n >> s >> e >> m;
    for(int i=0; i<m; i++){
        int u, v, w; cin >> u >> v >> w;
        edge[u].push_back(p(v, w));
    }
    for(int i=0; i<n; i++){
        cin >> pay[i];
        dist[i] = -INF;
    }
    bellman_ford();
    if(bfs()){
        cout << "Gee\n";
        return 0;
    }
    else{
        if(dist[e] == -INF)
            cout << "gg\n";
        else
            cout << dist[e] << '\n';
    }
}