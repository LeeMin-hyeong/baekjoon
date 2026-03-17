#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> c;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int start = 1, end = v[n-1]-v[0];
    int ans;
    while(start <= end){
        int mid = (start + end)/2;
        int cnt = 1;
        int prev = v[0];
        for(int i=1; i<n; i++){
            if(v[i] - prev >= mid){
                cnt++;
                prev = v[i];
            }
        }
        if(cnt < c){
            end = mid - 1;
        }
        else{
            start = mid + 1;
            ans = mid;
        }
    }
    cout << ans << '\n';
}