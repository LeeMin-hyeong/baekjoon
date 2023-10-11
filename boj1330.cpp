#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, k; cin >> n >> k;

    ll ans;
    ll high = n*n;
    ll low = 1;

    while(high >= low){
        ll mid = (high+low)/2;
        ll cnt = 0;

        for(int i=1; i<=n; i++){
            ll tmp = mid/i;
            cnt += tmp > n ? n : tmp;
        }
        if(cnt >= k){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout << ans << '\n';
}
