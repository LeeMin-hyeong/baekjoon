#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

long long dp[10][101];
int main(){
    int n; cin >> n;
    for(int i=1; i<10; i++)
        dp[i][1] = 1;
    for(int i=2; i<=n; i++)
        for(int j=0; j<10; j++)
            dp[j][i] += ((j>0?dp[j-1][i-1]:0)+(j<9?dp[j+1][i-1]:0))%MOD;
    long long ans = 0;
    for(int i=0; i<10; i++)
        ans += dp[i][n];
    cout << ans%MOD << '\n';
}