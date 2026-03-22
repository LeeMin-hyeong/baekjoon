#include <iostream>
#include <deque>
#include <cstring>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;
set<string> a, b;

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
        b.insert(s);
    }
    vector<string> c;
    set_intersection(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));
    cout << c.size() << '\n';
    for(auto i=c.begin(); i != c.end(); i++){
        cout << *i << '\n';
    }
}