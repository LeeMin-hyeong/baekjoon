#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
set<string> a;
vector<string> ans;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        string s; cin >> s;
        a.insert(s);
    }
    for(int i=0; i<m; i++){
        string s; cin >> s;
        if(a.count(s)){
            ans.push_back(s);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(auto i=0; i<ans.size(); i++){
        cout << ans[i] << '\n';
    }
}