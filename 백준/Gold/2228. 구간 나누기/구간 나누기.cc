#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int arr[105];
int sum[105];
int dp[105][105]; 
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> arr[i];
		sum[i] = sum[i-1]+arr[i];
	}
	for(int i=0; i<=n; i++){
		for(int j=0; j<=m; j++){
			dp[i][j] = -INF;
		}
	}
	for(int i=1; i<=n; i++){
		dp[i][1] = dp[i-1][1];
		for(int j=1; j<=i; j++){
			dp[i][1] = max(dp[i][1], sum[i]-sum[j-1]);
		}
	}
	for(int i=2; i<=m; i++){
		for(int j=2*i-1; j<=n; j++){
			dp[j][i] = dp[j-1][i];
			for(int k=2; k<=j; k++){
				dp[j][i] = max(dp[k-2][i-1]+sum[j]-sum[k-1], dp[j][i]);
			}
		}
	}
	cout << dp[n][m] << '\n';
}

