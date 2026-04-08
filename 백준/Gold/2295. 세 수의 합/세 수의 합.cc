#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> u, sum;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        u.push_back(a);
    }
    sort(u.begin(), u.end());

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            sum.push_back(u[i] + u[j]);
        }
    }
    sort(sum.begin(), sum.end());

    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            int target = u[i] - u[j];
            if(binary_search(sum.begin(), sum.end(), target)){
                cout << u[i] << '\n';
                return 0;
            }
        }
    }
}
