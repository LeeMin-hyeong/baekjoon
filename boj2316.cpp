#include <bits/stdc++.h>
#define OUT 400
using namespace std;

int cap[801][801], flow[801][801], parent[801];
int n, p;

int edmonds_karp(){
    int ans = 0;
    while(true){
        memset(parent, 0, sizeof(parent));
        queue<int> q;
        q.push(401);
        parent[401] = 401;
        while(!q.empty()){
            if(parent[2] != 0) break;
            int u = q.front(); q.pop();
            for(int v=1; v<801; v++){
                if(parent[v] == 0){
                    if(cap[u][v] - flow[u][v] > 0){
                        parent[v] = u;
                        q.push(v);
                    }
                }
            }
        }
        if(parent[2] == 0) break;

        int f = 0x7f7f7f7f;
        for(int i=2; i!=401; i=parent[i]){
            f = min(f, cap[parent[i]][i]-flow[parent[i]][i]);
        }
        for(int i=2; i!=401; i=parent[i]){
            flow[parent[i]][i] += f;
            flow[i][parent[i]] -= f;
        }
        ans += f;
    }
    return ans;
}

int main(){
    cin >> n >> p;
    for(int i=0; i<p; i++){
        int u, v; cin >> u >> v;
        cap[u+OUT][v] = 1;
        cap[v+OUT][u] = 1;

        cap[u][u+OUT] = 1;
        cap[v][v+OUT] = 1;
    }
    cout << edmonds_karp() << '\n';
}