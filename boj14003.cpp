#include <iostream>
#define MAX 1000001
#define INF 1000000001
using namespace std;

int arr[MAX];
int LIS[MAX];
int P[MAX];
int ans[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    LIS[0] = -INF;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        LIS[i] = INF;
    }
    for(int i=1; i<=n; i++){
        int index = lower_bound(LIS, LIS+n+1, arr[i])-LIS;
        P[i] = index;
        LIS[index] = min(LIS[index], arr[i]);
    }
    int length = *max_element(P+1, P+n+1);
    int find = length;
    for(int i=n; i>0; i--){
        if(P[i] == find){
            ans[find] = arr[i];
            find--;
        }
    }
    cout << length <<'\n';
    for(int i=1; i<=length; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}