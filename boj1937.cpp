#include <iostream>
using namespace std;

int forest[501][501];
int dp[501][501];
int x[] = {1, 0, -1, 0};
int y[] = {0, -1, 0, 1};
int n;

int move(int i, int j){
    if(i*j==0 || i>n || j>n) return 0;
    if(dp[i][j]>0) return dp[i][j];
    dp[i][j] = 1;
    for(int k=0; k<4; k++){
        if(forest[i][j] < forest[i+x[k]][j+y[k]])
            dp[i][j] = max(dp[i][j], move(i+x[k], j+y[k])+1);
    }
    return dp[i][j];
}

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin >> forest[i][j];

    int ans = 0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            ans = max(ans, move(i, j));

    cout << ans << "\n";
}