#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
vector<p> edges[1001];
stack<int> path;
int dist[1001];
int parent[1001];
int n, m, from, to;

int dijkstra(){
    priority_queue<p> pq;
    pq.push(p(0, from));
    dist[from] = 0;
    while(!pq.empty()){
        int w = -pq.top().first;
        int n = pq.top().second;
        pq.pop();
        if(w > dist[n]) continue;
        for(vector<p>::iterator itr=edges[n].begin(); itr!=edges[n].end(); itr++){
            if(dist[n]+itr->second < dist[itr->first]){
                parent[itr->first] = n;
                dist[itr->first] = dist[n]+itr->second;
                pq.push(p(-(dist[n]+itr->second), itr->first));
            }
        }
    }
    return dist[to];
}
void trace(int n){
    if(n == from) path.push(from);
    else{
        path.push(n);
        trace(parent[n]);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while(m--){
        int a, b, c; cin >> a >> b >> c;
        edges[a].push_back(p(b, c));
    }
    cin >> from >> to;
    memset(dist, 0x7f, sizeof(dist));
    cout << dijkstra() << '\n';
    trace(to);
    cout << path.size() << '\n';
    while(!path.empty()){
        cout << path.top() << ' ';
        path.pop();
    }
    cout << '\n';
}