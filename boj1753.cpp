#include <bits/stdc++.h>
#define INF 3333333
using namespace std;

typedef pair<int, int> p;
vector<p> edge[20001];
int cost[20001];
int n, m, from;

void dijkstra(){
    cost[from] = 0;
    priority_queue<p> pq;
    pq.push(p(0, from));
    while(!pq.empty()){
        int w = -pq.top().first;
        int n = pq.top().second;
        pq.pop();

        if(w > cost[n]) continue;
        vector<p>::iterator itr;
        for(itr=edge[n].begin(); itr!=edge[n].end(); itr++){
            if(cost[itr->first] > cost[n]+itr->second){
                cost[itr->first] = cost[n]+itr->second;
                pq.push(p(-(cost[n]+itr->second), itr->first));
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> from;
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        edge[a].push_back(p(b, c));
    }
    for(int i=1; i<20001; i++)
        cost[i] = INF;
    dijkstra();
    for(int i=1; i<=n; i++)
        if(cost[i] == INF)
            cout << "INF\n";
        else
            cout << cost[i] << '\n';
}