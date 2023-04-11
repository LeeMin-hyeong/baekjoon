#include <iostream>
using namespace std;

int arr[100001];
int incdp[100001];
int decdp[100001];
int main(){
    int n; cin >> n;
    for(int i=1; i<=n; i++){
        cin >> arr[i];
        incdp[i] = decdp[i] = 1;
    }
    for(int i=2; i<=n; i++){
        if(arr[i]>=arr[i-1]) incdp[i] = incdp[i-1]+1;
        if(arr[i]<=arr[i-1]) decdp[i] = decdp[i-1]+1;
    }
    cout << max(*max_element(incdp+1, incdp+1+n), *max_element(decdp+1, decdp+1+n)) << '\n';
}