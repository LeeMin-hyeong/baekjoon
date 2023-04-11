#include <iostream>
using namespace std;

int arr[1001];
int LIS[1001];
int P[1001];
int main(){
    int n; cin >> n;
    LIS[0] = 1001;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        LIS[i] = 0;
    }
    for(int i=1; i<=n; i++){
        int low = 0, high = n, index = 1001;
        while(high>=low){
            int mid = (high+low)/2;
            if(LIS[mid]<=arr[i]){
                index = min(index, mid);
                high = mid-1;
            }
            else low = mid+1;
        }
        P[i] = index;
        LIS[index] = max(LIS[index], arr[i]);
    }
    cout << *max_element(P+1, P+n+1) << '\n';
}