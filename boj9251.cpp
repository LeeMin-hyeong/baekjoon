// #include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int L[1001][1001];
string N;
string M;

int main(){
    memset(L, 0, sizeof(L));
    cin >> N >> M;
    int n = N.size();
    int m = M.size();

    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(N[i-1] == M[j-1]) L[i][j] = L[i-1][j-1]+1;
            else L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }
    cout << L[n][m] << "\n";
}