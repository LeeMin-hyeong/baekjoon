#include <bits/stdc++.h>
using namespace std;

int tc;
long long dp[501][501];
int sum[501];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while(tc--){
        int k; cin >> k;
        for(int i=1; i<=k; i++){
            for(int j=1; j<=k; j++){
                dp[i][j] = 1e10;
            }
        }
        for(int i=1; i<=k; i++){
            int a; cin >> a;
            sum[i] = sum[i-1] + a;
            dp[i][i] = 0;
        }
        for(int j=0; j<k; j++){
            for(int i=1; i+j<=k; i++){
                for(int h=i; h<i+j; h++){
                    dp[i][i+j] = min(dp[i][i+j], dp[i][h] + sum[h]-sum[i-1] + dp[h+1][i+j] + sum[i+j]-sum[h]);
                }
            }
        }
        cout << dp[1][k] << '\n';
    }
}
