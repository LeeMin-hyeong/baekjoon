#include <bits/stdc++.h>
using namespace std;

int cost[1000][3];
int dp[1000][3];
int n;

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    int ans = 1000001;
    for(int k=0; k<3; k++){
        dp[0][0] = 1000001;
        dp[0][1] = 1000001;
        dp[0][2] = 1000001;
        dp[0][k] = cost[0][k];
        for(int i=1; i<n; i++){
            dp[i][0] = min(dp[i-1][1]+cost[i][0], dp[i-1][2]+cost[i][0]);
            dp[i][1] = min(dp[i-1][0]+cost[i][1], dp[i-1][2]+cost[i][1]);
            dp[i][2] = min(dp[i-1][0]+cost[i][2], dp[i-1][1]+cost[i][2]);
        }
        for(int i=0; i<3; i++){
            if(i == k) continue;
            ans = min(ans, dp[n-1][i]);
        }
    }
    cout << ans << '\n';
}