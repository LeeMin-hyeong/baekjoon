#include <iostream>
using namespace std;

int dp[101][51]; //dp[i][j]: 1~i 의 배열로 j개의 구간을 만들었을 때 구간 합의 최댓값
int sum[101];
int main(){
    int N, M;
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        int a; cin >> a;
        sum[i] = sum[i-1]+a;
    }
    for(int j=0; j<=M; j++){
        for(int i=0; i<=N; i++){
            dp[i][j] = -3276800;
        }
    }
    for(int j=1; j<=M; j++){
        for(int i=2*j-1; i<=N; i++){
            dp[i][j] = dp[i-1][j];
            for(int k=1; k<=i; k++){
                if(j==1) dp[i][j] = max(dp[i][j], sum[i]-sum[k-1]);
                else if(k>1) dp[i][j] = max(dp[i][j], dp[k-2][j-1]+sum[i]-sum[k-1]);
            }
        }
    }
    cout << dp[N][M] << "\n";
}