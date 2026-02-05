#include <bits/stdc++.h>
using namespace std;

int dp[100001][2];
int arr[100001];
int ans;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    dp[1][0] = ans = arr[1];
    dp[1][1] = 0;
    for(int i=2; i<=n; i++){
        dp[i][0] = max(dp[i-1][0]+arr[i], arr[i]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][1]+arr[i]);
        ans = max(ans, max(dp[i][0], dp[i][1]));
    }
    cout << ans << '\n';
}