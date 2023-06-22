#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
priority_queue<iii> pq;
int parent[10001], v, e;

int find(int p){
    while(p != parent[p]) p = parent[p];
    return p;
}

bool union_tree(int p, int q){
    int pp = find(p);
    int pq = find(q);
    if(pp == pq) return false;
    if(pp < pq) parent[pq] = pp;
    else parent[pp] = pq;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e;
    for(int i=0; i<e; i++){
        int a, b, c; cin >> a >> b >> c;
        pq.push(iii(-c, ii(a, b)));
    }
    for(int i=1; i<=v; i++)
        parent[i] = i;

    int ans = 0;
    while(!pq.empty()){
        int w = -pq.top().first;
        int p = pq.top().second.first;
        int q = pq.top().second.second;
        pq.pop();
        if(union_tree(p, q)) ans += w;
    }
    cout << ans << '\n';
}
