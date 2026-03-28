#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[5001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<5001; i++){
        dp[i] = 1e5;
    }
    dp[3] = 1; dp[5] = 1;
    for(int i=6; i<=n; i++){
        dp[i] = min(dp[i-3], dp[i-5])+1;
    }
    cout << (dp[n] >= 1e5 ? -1 : dp[n]) << '\n';
}