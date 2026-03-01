#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

typedef struct{
    int m;
    int x;
    int y;
    int z;
} planet;

int n, cnt;
int parent[100001];
vector<planet> p;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
long long ans;

int find(int p){
    if(p == parent[p]) return p;
    return parent[p] = find(parent[p]);
}

bool union_tree(int p, int q){
    int pp = find(p);
    int pq = find(q);
    if(pp == pq) return false;
    if(pp < pq) parent[pq] = pp;
    else parent[pp] = pq;
    return true;
}

int distance(planet a, planet b){
    return min(min(abs(a.x-b.x), abs(a.y-b.y)), abs(a.z-b.z));
}

bool compare_x(planet a, planet b){
    return a.x < b.x;
}
bool compare_y(planet a, planet b){
    return a.y < b.y;
}
bool compare_z(planet a, planet b){
    return a.z < b.z;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        p.push_back({i, x, y, z});
    }
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    sort(p.begin(), p.end(), compare_x);
    for(int i=0; i<p.size()-1; i++){
        pq.push({distance(p[i], p[i+1]), p[i].m, p[i+1].m});
    }
    sort(p.begin(), p.end(), compare_y);
    for(int i=0; i<p.size()-1; i++){
        pq.push({distance(p[i], p[i+1]), p[i].m, p[i+1].m});
    }
    sort(p.begin(), p.end(), compare_z);
    for(int i=0; i<p.size()-1; i++){
        pq.push({distance(p[i], p[i+1]), p[i].m, p[i+1].m});
    }
    while(!pq.empty()){
        int w = get<0>(pq.top());
        int p = get<1>(pq.top());
        int q = get<2>(pq.top());
        pq.pop();
        if(union_tree(p, q)){
            ans += w;
            cnt++;
        }
        if(cnt == n-1){
            break;
        }
    }
    cout << ans << '\n';
}