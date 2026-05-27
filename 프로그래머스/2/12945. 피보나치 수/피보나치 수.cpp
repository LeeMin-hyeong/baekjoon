#include <string>
#include <vector>

using namespace std;

int dp[100'001];

int solution(int n) {
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        int pp = dp[0], p = dp[1];
        int np = (pp+p)%1234567;
        dp[0] = p;
        dp[1] = np;
    }
    return dp[1];
}