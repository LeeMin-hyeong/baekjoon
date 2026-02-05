#include <bits/stdc++.h>
using namespace std;

int dp[100001];
int main(){
    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        int w, v; cin >> w >> v;
        for(int j=k; j>=w; j--)
            dp[j] = max(dp[j], dp[j-w]+v);
    }
    cout << dp[k] << '\n';
}