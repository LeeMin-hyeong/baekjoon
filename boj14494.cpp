// #include <bits/stdc++.h>
#include <iostream>
using namespace std;

long long mem[1001][1001];
long long mod = 1000000007;

int main(){
    int n, m;
    cin >> n >> m;

    for(int i=1; i<=n; i++)
        mem[i][1] = 1;
    for(int i=1; i<=m; i++)
        mem[1][i] = 1;
    
    for(int i=2; i<=n; i++)
        for(int j=2; j<=m; j++)
            mem[i][j] = (mem[i-1][j-1] + mem[i-1][j] + mem[i][j-1])%mod;
    cout << mem[n][m] << "\n";
}