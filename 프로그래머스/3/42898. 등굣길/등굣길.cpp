#include <string>
#include <vector>

using namespace std;

int dp[101][101];
bool p[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(auto puddle : puddles){
        p[puddle[1]][puddle[0]] = true;
    }
    
    dp[0][1] = 1;
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(p[i][j]) continue;
            dp[i][j] = (dp[i-1][j]+dp[i][j-1]) % 1'000'000'007;
        }
    }

    return dp[n][m];
}