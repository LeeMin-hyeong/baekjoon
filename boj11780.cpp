#include <bits/stdc++.h>
using namespace std;

int d[101][101], p[101][101];
int n, m;
vector<int> v;

void floyd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(d[i][j] > d[i][k]+d[k][j]){
                    d[i][j] = d[i][k]+d[k][j];
                    p[i][j] = k;
                }
            }
        }
    }
}

int main(){
    cin >> n >> m;
    memset(d, 0x3f, sizeof(d));
    for(int i=1; i<=n; i++){
        d[i][i] = 0;
    }
    for(int i=0; i<m; i++){
        int u, v, w; cin >> u >> v >> w;
        if(d[u][v] > w){
            d[u][v] = w;
            p[u][v] = v;
        }
    }
    floyd();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(d[i][j]>1000000000) cout << 0 << ' ';
            else cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            
        }
    }
}