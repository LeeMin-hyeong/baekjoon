#include <iostream>
using namespace std;

bool prime[40001];
int dp[40001];
int main(){
    int mod = 123456789;
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i=2; i<=40000; i++)
        for(int j=2; j*i<=40000; j++)
            if(prime[i]) prime[i*j] = false;
    int n; cin >> n;
    dp[0] = 1;
    for(int j=2; j<=n; j++)
        if(prime[j])
            for(int i=j; i<=n; i++)
                (dp[i] += dp[i-j])%=mod;
    cout << dp[n] << '\n';
}