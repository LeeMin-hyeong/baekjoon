#include <iostream>
#define MAX 987654321
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    while(true){
        ++cnt;
        int n; cin >> n;
        if(n==0) break;

        int graph[n][3];
        long long dp[n][3];
        for(int i=0; i<n; i++)
            for(int j=0; j<3; j++)
                cin >> graph[i][j];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = MAX;
        dp[0][1] = graph[0][1];
        dp[0][2] = graph[0][1] + graph[0][2];
        for(int i=1; i<n; i++){
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]) + graph[i][0];
            dp[i][1] = min(min(dp[i-1][0], dp[i-1][1]), min(dp[i][0], dp[i-1][2])) + graph[i][1];
            dp[i][2] = min(min(dp[i-1][1], dp[i-1][2]), dp[i][1]) + graph[i][2];
        }
        cout << cnt << ". " << dp[n-1][1] << "\n";
    }
}