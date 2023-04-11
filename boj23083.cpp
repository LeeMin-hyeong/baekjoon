#include <iostream>
#include <cstring>
using namespace std;

long long dp[1005][1005];
long long mod = 1000000007;
int n, m, k;

long long move(int i, int j){
    long long &ret = dp[i][j];
    if(ret != -1) return dp[i][j];
    else if(i<1 || j<1 || i>n || j>m) ret = 0;
    else if(i==1 && j==1) ret = 1;

    else if(j%2==0) ret = (move(i-1, j)%mod+move(i, j-1)%mod+move(i+1, j-1)%mod)%mod;
    else ret = (move(i-1, j)%mod+move(i, j-1)%mod+move(i-1, j-1)%mod)%mod;
    return ret;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;
    while(k--){
        int i, j; cin >> i >> j;
        dp[i][j]=0;
    }
    move(n, m);
    cout << dp[n][m] << '\n';
}