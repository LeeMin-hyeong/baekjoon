#include <iostream>
using namespace std;

int arr[10001];
int dp[10001][3];
int main(){
    int n; cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    dp[1][1] = arr[1];
    for(int i=2; i<=n; i++){
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        dp[i][1] = dp[i-1][0]+arr[i];
        dp[i][2] = dp[i-1][1]+arr[i];
    }
    int ans = 0;
    for(int i=0; i<3; i++)
        ans = max(ans, dp[n][i]);
    cout << ans << '\n';
}