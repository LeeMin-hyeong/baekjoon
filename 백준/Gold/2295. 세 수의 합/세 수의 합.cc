#include <iostream>
#include <vector>
#include <algorithm>
// #include <unordered_map>
#include <set>
using namespace std;

int n;
vector<int> u;
// unordered_map<int, bool> m;
set<int> s;

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
            // m[u[i] + u[j]] = true;
            s.insert(u[i] + u[j]);
        }
    }

    for(int i=n-1; i>=0; i--){
        for(int j=0; j<n; j++){
            int target = u[i] - u[j];
            // if(m[target]){
            if(s.find(target) != s.end()){
                cout << u[i] << '\n';
                return 0;
            }
        }
    }
}
