#include <bits/stdc++.h>
using namespace std;

int n;
typedef pair<int, int> p;
vector<p> v;
int dp[501][501];

int main(){
    cin >> n;
    v.push_back(p(0, 0));
    for(int i=0; i<n; i++){
        int r, c; cin >> r >> c;
        v.push_back(p(r, c));
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            dp[j][i+j] = 0x7f7f7f7f;
            for(int k=j; k<i+j; k++){
                dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + v[j].first * v[k].second * v[i+j].second);
            }
        }
    }
    cout << dp[1][n] << '\n';
}