#include <bits/stdc++.h>
using namespace std;

int dp[10][101][1024];
int ans;
int n;

int main(){
    cin >> n;
    //dp[selected][len][mask]
    for(int i=1; i<10; i++){
        dp[i][1][1<<i] = 1;
    }
    for(int len=1; len<n; len++){
        for(int s=0; s<10; s++){
            for(int mask=0; mask<1024; mask++){
                if(dp[s][len][mask] > 0){
                    if(s > 0){
                        dp[s-1][len+1][mask | (1 << (s-1))] += dp[s][len][mask];
                        dp[s-1][len+1][mask | (1 << (s-1))] %= 1'000'000'000;
                    }
                    if(s < 9){
                        dp[s+1][len+1][mask | (1 << (s+1))] += dp[s][len][mask];
                        dp[s+1][len+1][mask | (1 << (s+1))] %= 1'000'000'000;
                    }
                }
            }
        }
    }
    
    for(int i=0; i<10; i++){
        ans += dp[i][n][1023];
        ans %= 1'000'000'000;
    }
    cout << ans << '\n';
}