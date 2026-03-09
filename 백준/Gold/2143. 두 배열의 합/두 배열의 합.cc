#include <iostream>
#include <unordered_map>
using namespace std;

int t, n, m;
long long ans;
int a[1001], b[1001], sum_a[1001], sum_b[1001];
unordered_map<int, int> pa;

int main(){
    cin >> t;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        sum_a[i] = sum_a[i-1] + a[i];
    }
    cin >> m;
    for(int i=1; i<=m; i++){
        cin >> b[i];
        sum_b[i] = sum_b[i-1] + b[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j++){
            pa[sum_a[j] - sum_a[i-1]]++;
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=i; j<=m; j++){
            ans += pa[t - (sum_b[j] - sum_b[i-1])];
        }
    }
    cout << ans << '\n';
}