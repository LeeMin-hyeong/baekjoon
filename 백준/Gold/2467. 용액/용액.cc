#include <bits/stdc++.h>
using namespace std;

int n;
int l[100000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> l[i];
    }
    int high = n-1, low = 0;
    int ans = abs(l[low]+l[high]);
    int ans_a = l[low], ans_b = l[high];
    while(high > low){
        int mixed = l[low]+l[high];
        if(abs(mixed) < ans){
            ans = abs(mixed);
            ans_a = l[low];
            ans_b = l[high];
        }
        if(mixed > 0) high--;
        else low++;
    }
    cout << ans_a << ' ' << ans_b << '\n';
}