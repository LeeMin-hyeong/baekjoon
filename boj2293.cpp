#include <iostream>
using namespace std;

long long dp[10001];
int main(){
    int N, K;
    cin >> N >> K;
    int coin[N];
    for(int i=0; i<N; i++)
        cin >> coin[i];
    // dp[0]=1;
    // for(int i=0; i<N; i++){
    //     for(int j=K; j>=0; j--){
    //         for(int k=1; coin[i]*k<=K; k++){
    //             if(j-coin[i]*k >= 0)
    //                 dp[j] += dp[j-coin[i]*k];
    //         }
    //     }
    // }
    // cout << dp[K] << "\n";
    // memset(dp, 0, sizeof(dp));
    dp[0]=1;
    for(int i=0; i<N; i++){
        for(int j=1; j<=K; j++)
            if(j-coin[i]>=0)
                dp[j] += dp[j-coin[i]];
    }
    cout << dp[K] << "\n";
}