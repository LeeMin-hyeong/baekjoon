#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> sche[16];
int dp[17];

int main(){
    cin >> n;
    for(int i=1; i<=n; i++){
        int t, p; cin >> t >> p;
        sche[i] = {t, p};
    }
    for(int i=n; i>0; i--){
        if(i+sche[i].first-1 <= n){
            dp[i] = max(dp[i+1], sche[i].second + dp[i+sche[i].first]);
        }
        else{
            dp[i] = max(dp[i+1], dp[i]);
        }
    }
    cout << dp[1] << '\n';
}