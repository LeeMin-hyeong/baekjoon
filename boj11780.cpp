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

void path(int i, int j){
    if(p[i][j] == 0){
        v.push_back(i);
        v.push_back(j);
        return;
    }
    path(i, p[i][j]);
    v.pop_back();
    path(p[i][j], j);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    memset(d, 0x3f, sizeof(d));
    for(int i=1; i<=n; i++){
        d[i][i] = 0;
    }
    for(int i=0; i<m; i++){
        int u, v, w; cin >> u >> v >> w;
        if(d[u][v] > w){
            d[u][v] = w;
        }
    }
    floyd();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(d[i][j] > 1000000000) cout << 0 << ' ';
            else cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            v.clear();
            if(d[i][j] > 1000000000 || d[i][j] == 0){
                cout << "0\n";
                continue;
            }
            path(i, j);
            cout << v.size() << ' ';
            for(int i=0; i<v.size(); i++){
                cout << v[i] << ' ';
            }
            cout << '\n';
        }
    }
}