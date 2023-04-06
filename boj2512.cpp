#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n, m, sum = 0, ans = 0;
    cin >> n;
    int req[n];
    for(int i=0; i<n; i++){
        cin >> req[i];
        sum += req[i];
    }
    cin >> m;
    if(sum <= m) cout << *max_element(req, req+n) << "\n";
    else{
        int low = 1;
        int high = sum;
        while(high >= low){
            int mid = (high + low)/2;
            int expect = 0;
            for(int i=0; i<n; i++){
                if(req[i] < mid)
                    expect += req[i];
                else
                    expect += mid;
            }
            
            if(expect <= m){
                low = mid+1;
                ans = mid;
            }
            else
                high = mid-1;
        }
        cout << ans << "\n";
    }
}