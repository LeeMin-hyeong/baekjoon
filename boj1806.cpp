#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[100001], sum[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        sum[i] = sum[i-1]+arr[i];
    }
    int ans = n;
    int f = 0, b = 0;
    bool na = true;
    while(f <= b && b <= n){
        int tmp = sum[b]-sum[f];
        if(tmp < s){
            b++;
        }
        else if(tmp >= s){
            na = false;
            ans = min(ans, b-f);
            f++;
        }
    }
    if(na) cout << 0 << '\n';
    else cout << ans << '\n';
}   