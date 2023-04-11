#include <iostream>
#define INF 987654321
using namespace std;

int dp[100001];
int main(){
    int n; cin >> n;
    // dp[0] = 0;
    for(int i=1; i<=n; i++)
        dp[i] = min((i-2>=0?dp[i-2]+1:INF),(i-5>=0?dp[i-5]+1:INF));
    if(dp[n]!=INF) cout << dp[n] << '\n';
    else cout << "-1" << '\n';
}