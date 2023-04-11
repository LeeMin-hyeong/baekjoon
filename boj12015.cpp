#include <iostream>
#define MAX 1000001
using namespace std;

int arr[MAX];
int LIS[MAX];
int P[MAX];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    LIS[0] = -1;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        LIS[i] = MAX;
    }
    for(int i=1; i<=n; i++){
        int index = lower_bound(LIS, LIS+n+1, arr[i])-LIS;
        P[i] = index;
        LIS[index] = min(LIS[index], arr[i]);
    }
    cout << *max_element(P+1, P+n+1) << '\n';
}