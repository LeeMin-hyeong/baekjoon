#include <bits/stdc++.h>
using namespace std;

int tc;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while(tc--){
        long long dp[501][501];
        int opt[501][501];
        int sum[501];
        sum[0] = 0;
        int k; cin >> k;
        for(int i=1; i<=k; i++){
            for(int j=1; j<=k; j++){
                dp[i][j] = 1e10;
                opt[i][j] = i;
            }
        }
        for(int i=1; i<=k; i++){
            int a; cin >> a;
            sum[i] = sum[i-1] + a;
            dp[i][i] = 0;
        }
        for(int len=2; len<=k; len++){
            for(int i=1; i+len-1<=k; i++){
                int j = i+len-1;

                int s = opt[i][j-1];
                int e = opt[i+1][j];

                for(int h=s; h<=e; h++){
                    if(dp[i][j] > dp[i][h] + dp[h+1][j] + sum[j] - sum[i-1]){
                        dp[i][j] = dp[i][h] + dp[h+1][j] + sum[j] - sum[i-1];
                        opt[i][j] = h;
                    }
                }
            }
        }
        cout << dp[1][k] << '\n';
    }
}
