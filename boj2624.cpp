#include <iostream>
#include <cstring>
#include <map>
using namespace std;

long long dp[10001];

int main(){
    //입력
    int n, k;
    cin >> k >> n;
    multimap<int, long long> m;
    for(int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        m.insert(pair<int, long long>(a, b));
    }

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    multimap<int, long long>::iterator itr;
    for(itr=m.begin(); itr!=m.end(); itr++)
        for(int i=k; i>0; i--)
            for(int j=1; j<=itr->second; j++)
                if(i - (itr->first) * j >=0)
                    dp[i] += dp[i-(itr->first)*j];

    cout << dp[k] << "\n";
}