#include <iostream>
using namespace std;

int dp[1001][3];
int house[1001][3];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i=1; i<=n; i++)
        cin >> house[i][0] >> house[i][1] >> house[i][2];
    dp[1][0] = house[1][0];
    dp[1][1] = house[1][1];
    dp[1][2] = house[1][2];
    for(int i=2; i<=n; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + house[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + house[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + house[i][2];
    }
    int ans = 987654321;
    for(int i=0; i<3; i++)
        ans = min(ans, dp[n][i]);
    cout << ans << '\n';
}