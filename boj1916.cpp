#include <iostream>
#define INF 987654321
using namespace std;

int dp[1001][1001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            dp[i][j] = INF;
        }
    }
    while(m--){
        int i, j, v;
        cin >> i >> j >> v;
        dp[i][j] = v;
    }
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            for(int k=i+1; k<j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }
    int from, to;
    cin >> from >> to;
    cout << dp[from][to] << '\n';
}