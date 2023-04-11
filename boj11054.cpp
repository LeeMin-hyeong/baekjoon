#include <iostream>
using namespace std;

int arr[1001];
int LIS[1001];
int revLIS[1001];
int P[1001];
int revP[1001];

int main(){
    int n; cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        LIS[i] = 1001;
        revLIS[i] = 1001;
    }
    LIS[0] = -1;
    for(int i=1; i<=n; i++){
        int index = lower_bound(LIS, LIS+n+1, arr[i])-LIS;
        P[i] = index;
        LIS[index] = min(LIS[index], arr[i]);
    }
    for(int i=1; i<=n; i++)
        cout << P[i] << ' ';
    cout << '\n';
    revLIS[0] = -1;
    for(int i=n; i>0; i--){
        int index = lower_bound(revLIS, revLIS+n+1, arr[i])-revLIS;
        revP[i] = index;
        revLIS[index] = min(revLIS[index], arr[i]);
    }
    for(int i=1; i<=n; i++)
        cout << revP[i] << ' ';
    cout << '\n';
    int ans = 0;
    for(int i=1; i<=n; i++)
        ans = max(ans, P[i]+revP[i]-1);
    cout << ans << '\n';
}