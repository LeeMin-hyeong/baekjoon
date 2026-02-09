#include <bits/stdc++.h>
using namespace std;

int cost[1000][3];
int dp[1000][3][3];
int n;

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    dp[0][0][0] = cost[0][0];
    dp[0][0][1] = 1001;
    dp[0][0][2] = 1001;
    dp[0][1][0] = 1001;
    dp[0][1][1] = cost[0][1];
    dp[0][1][2] = 1001;
    dp[0][2][0] = 1001;
    dp[0][2][1] = 1001;
    dp[0][2][2] = cost[0][2];

    for(int k=0; k<3; k++){
        for(int i=1; i<n-1; i++){
            dp[i][0][k] = min(dp[i-1][1][k]+cost[i][0], dp[i-1][2][k]+cost[i][0]);
            dp[i][1][k] = min(dp[i-1][0][k]+cost[i][1], dp[i-1][2][k]+cost[i][1]);
            dp[i][2][k] = min(dp[i-1][0][k]+cost[i][2], dp[i-1][1][k]+cost[i][2]);
        }
    }
    for(int k=0; k<3; k++){
        if(k != 0) dp[n-1][0][k] = min(dp[n-2][1][k]+cost[n-1][0], dp[n-2][2][k]+cost[n-1][0]);
        if(k != 1) dp[n-1][1][k] = min(dp[n-2][0][k]+cost[n-1][1], dp[n-2][2][k]+cost[n-1][1]);
        if(k != 2) dp[n-1][2][k] = min(dp[n-2][0][k]+cost[n-1][2], dp[n-2][1][k]+cost[n-1][2]);
    }
    int ans = 1000001;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i == j) continue;
            ans = min(ans, dp[n-1][i][j]);
        }
    }
    cout << ans << '\n';
}