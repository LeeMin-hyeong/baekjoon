#include <bits/stdc++.h>

#define MAXV 1000000007

using namespace std;
using i64 = long long int;

i64 dp[1005][1005];
int n, m;

i64 calc(int x, int y) {
    auto& res = dp[x][y];
    
    if (x < 1 || n < x || y < 1 || m < y)
        return res = 0;
    
    if (x == 1 && y == 1) {
        return res = 1;
    }
    
    if (dp[x][y] != -1)
        return dp[x][y];

    if (y % 2 == 0) {
        res = calc(x-1, y) + calc(x, y-1) + calc(x+1, y-1);
    } else {
        res = calc(x-1, y) + calc(x-1, y-1) + calc(x, y-1);
    }
    
    return res %= MAXV;
}

int main() {
    memset(dp, -1, sizeof(dp));
    
    scanf("%d %d", &n, &m);
    
    int k;
    scanf("%d", &k);
    
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        
        dp[x][y] = 0;
    }
    
    printf("%d\n", calc(n, m));
    
    return 0;
}