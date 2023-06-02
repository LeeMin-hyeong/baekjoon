#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
vector<p> BUS[1001];
int cost[1001];
int n, m, from, to;

int dijkstra(){
    cost[from] = 0;
    priority_queue<p> pq;
    pq.push(p(0, from));
    while(!pq.empty()){
        int w = -pq.top().first;
        int n = pq.top().second;
        pq.pop();

        if(w > cost[n]) continue;
        vector<p>::iterator itr;
        for(itr=BUS[n].begin(); itr!=BUS[n].end(); itr++){
            if(cost[itr->first] > cost[n]+itr->second){
                cost[itr->first] = cost[n]+itr->second;
                pq.push(p(-(cost[n]+itr->second), itr->first));
            }
        }
    }
    return cost[to];
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        BUS[a].push_back(p(b, c));
    }
    cin >> from >> to;
    memset(cost, 0x7f, sizeof(cost));
    cout << dijkstra() << '\n';
}