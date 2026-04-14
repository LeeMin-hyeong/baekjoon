#include <iostream>
using namespace std;

int n;
int a[11];
int op_cnt[4];
int ans1 = -1'000'000'000, ans2 = 1'000'000'000; 

void bt(int idx, int ret){
    if(idx == n){
        ans1 = max(ans1, ret);
        ans2 = min(ans2, ret);
        return;
    }
    for(int i=0; i<4; i++){
        if(op_cnt[i] > 0){
            op_cnt[i]--;
            if(i == 0) bt(idx+1, ret+a[idx]);
            if(i == 1) bt(idx+1, ret-a[idx]);
            if(i == 2) bt(idx+1, ret*a[idx]);
            if(i == 3) bt(idx+1, ret/a[idx]);
            op_cnt[i]++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int i=0; i<4; i++){
        cin >> op_cnt[i];
    }
    bt(1, a[0]);
    cout << ans1 << '\n' << ans2 << '\n';
}