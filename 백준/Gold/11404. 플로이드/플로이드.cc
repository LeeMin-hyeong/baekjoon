#include <bits/stdc++.h>
#define INF 10000000001
using namespace std;

long long cost[101][101];
int n, m;
void floyd(){
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i == j || i == k || j == k) continue;
                cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cost[i][j] = INF;
        }
    }
    for(int i=0; i<m; i++){
        int a, b, c; cin >> a >> b >> c;
        cost[a][b] = min(cost[a][b], (long long)c);
    }
    floyd();
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(cost[i][j] == INF) cout << "0 ";
            else cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }
}