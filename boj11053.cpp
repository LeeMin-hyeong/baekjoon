#include <iostream>
using namespace std;

int arr[1001];
int LIS[1001];
int P[1001];
int main(){
    int n; cin >> n;
    LIS[0] = -1;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        LIS[i] = 1001;
    }
    for(int i=1; i<=n; i++){
        int index = lower_bound(LIS, LIS+n+1, arr[i])-LIS;
        P[i] = index;
        if(arr[i]<LIS[index])
            LIS[index] = arr[i];
    }
    cout << *max_element(P+1, P+n+1) << '\n';
}