#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int n, cnt, ans;
int parent[301];

typedef tuple<int, int, int> edge;
priority_queue<edge, vector<edge>, greater<edge>> pq;

int find(int p){
    if(p == parent[p]) return p;
    return parent[p] = find(parent[p]);
}

bool union_find(int p, int q){
    int pp = find(p);
    int pq = find(q);
    if(pp == pq) return false;
    if(pp < pq) parent[pq] = pp;
    else parent[pp] = pq;
    return true;
}

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int w; cin >> w;
        pq.push({w, 0, i});
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int w; cin >> w;
            if(i < j) pq.push({w, i, j});
        }
    }
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    while(!pq.empty()){
        int w = get<0>(pq.top());
        int p = get<1>(pq.top());
        int q = get<2>(pq.top());
        pq.pop();
        if(union_find(p, q)){
            ans += w;
            cnt++;
        }
        if(cnt == n) break;
    }
    cout << ans << '\n';
}