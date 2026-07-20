#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


long long solution(vector<vector<int>> land, int P, int Q) {
    long long ans = 1000000000LL * 100 * 300 * 300;
    int n = land.size();

    vector<long long> v;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            v.push_back(land[i][j]);
        }
    }
    sort(v.begin(), v.end());
    vector<long long> sum(n*n, 0);
    sum[0] = v[0];
    for(int i=1; i<n*n; i++){
        sum[i] = v[i]+sum[i-1];
    }
    int prev = -1;
    for(int i=0; i<n*n; i++){
        if(prev == v[i]) continue;
        prev = v[i];
        long long p=0, q=0;

        for(int j=i-1; j>=0; j--){
            if(v[j] != v[i]){
                p = v[i]*(j+1) - sum[j];
                break;
            }
        }

        for(int j=i+1; j<n*n; j++){
            if(v[j] != v[i]){
                q = sum[n*n-1] - sum[j-1] - v[i]*(n*n-j);
                break;
            }
        }

        ans = min(ans, (p*P+q*Q));
    }
    return ans;
}