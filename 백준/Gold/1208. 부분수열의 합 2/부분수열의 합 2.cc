#include <iostream>
#include <unordered_map>
using namespace std;

int n, s;
long long ans;
int arr[40];
unordered_map<int, int> m;

void right(int i, int sum){
    if(i == n){
        m[sum]++;
        return;
    }
    right(i+1, sum+arr[i]);
    right(i+1, sum);
}

void left(int i, int sum){
    if(i == n/2){
        ans += m[s-sum];
        return;
    }
    left(i+1, sum+arr[i]);
    left(i+1, sum);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    right(n/2, 0);
    left(0, 0);

    cout << (s == 0 ? ans-1 : ans) << '\n';
}