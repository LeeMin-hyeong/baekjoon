#include <bits/stdc++.h>
using namespace std;

int dp[10001];
int main(){
    int N, T; cin >> N >> T;
    for(int i=0; i<N; i++){
        int k, s; cin >> k >> s;
        for(int j=T; j>=k; j--)
            dp[j] = max(dp[j], dp[j-k]+s);
    }
    cout << dp[T] << "\n";
}