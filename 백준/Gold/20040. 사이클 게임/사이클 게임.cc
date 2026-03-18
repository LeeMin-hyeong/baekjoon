#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int parent[500000];

int find(int a){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

bool union_find(int a, int b){
    int pa = find(a);
    int pb = find(b);
    if(pa == pb) return false;
    if(pa < pb) parent[pb] = pa;
    else parent[pa] = pb;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        parent[i]=i;
    }
    int ans = 0;
    for(int i=1; i<=m; i++){
        int a, b; cin >> a >> b;
        if(ans == 0 && !union_find(a, b)){
            ans = i;
        }
    }
    cout << ans << '\n';
}