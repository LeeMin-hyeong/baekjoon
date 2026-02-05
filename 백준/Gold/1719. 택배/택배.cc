#include <bits/stdc++.h>
using namespace std;

int ans[201][201];
int dist[201][201];
int n, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dist, 0x3f, sizeof(dist));
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int u, v, w; cin >> u >> v >> w;
        if(dist[u][v] > w){
            dist[u][v] = w;
            ans[u][v] = v;
        }
        if(dist[v][u] > w){
            dist[v][u] = w;
            ans[v][u] = u;
        }
    }

    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    ans[i][j] = ans[i][k];
                }
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) cout << "- ";
            else cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}