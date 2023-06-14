#include <bits/stdc++.h>
using namespace std;

int parent[100001];
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int n, m;

int find(int p){
    while(p != parent[p]) p = parent[p];
    return p;
}

bool union_find(int p, int q){
    int pp = find(p);
    int pq = find(q);
    if(pp == pq) return false;
    if(pp > pq) parent[pq] = pp;
    else parent[pp] = pq;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    priority_queue<iii> pq;
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        pq.push(iii(-c, ii(a, b)));
    }
    for(int i=1; i<=n; i++) parent[i] = i;

    int ans = 0, cnt = 0;
    while(!pq.empty()){
        int w = -pq.top().first;
        int a = pq.top().second.first;
        int b = pq.top().second.second;
        pq.pop();

        if(cnt == n-2) break;
        if(union_find(a, b)){
            ans += w;
            cnt++;
        }
    }
    cout << ans << '\n';
}

