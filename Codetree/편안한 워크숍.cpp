#include <iostream>
using namespace std;

int mountain[100][100];
int dp[100][100][101];
int n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> mountain[i][j];
        }
    }
    
    for(int h=2; h<=100; h++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j][h] = 1e8;
            }
        }
    }

    for(int h=2; h<=k; h++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int up = 1e8, down = 1e8, left = 1e8, right = 1e8;
                if(i-1 >= 0 && mountain[i][j] > mountain[i-1][j]){
                    up = max(dp[i-1][j][h-1], mountain[i][j]-mountain[i-1][j]);
                }
                if(i+1 < n && mountain[i][j] > mountain[i+1][j]){
                    down = max(dp[i+1][j][h-1], mountain[i][j]-mountain[i+1][j]);
                }
                if(j-1 >= 0 && mountain[i][j] > mountain[i][j-1]){
                    left = max(dp[i][j-1][h-1], mountain[i][j]-mountain[i][j-1]);
                }
                if(j+1 < n && mountain[i][j] > mountain[i][j+1]){
                    right = max(dp[i][j+1][h-1], mountain[i][j]-mountain[i][j+1]);
                }
                dp[i][j][h] = min(min(up, down), min(left, right));
            }
        }
    }

    int ans = 1e8;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = min(ans, dp[i][j][k]);
        }
    }
    if(ans == 1e8){
        cout << -1 << '\n';
    }
    else{
        cout << ans << '\n';
    }
}
