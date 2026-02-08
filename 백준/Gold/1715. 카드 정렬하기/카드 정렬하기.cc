#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    priority_queue<int> q;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        q.push(-a);
    }
    int ans = 0;
    int c1, c2, nc;
    while(!q.empty() && n > 1){
        c1 = -q.top();
        q.pop();
        c2 = -q.top();
        q.pop();
        nc = c1 + c2;
        ans += nc;
        if(!q.empty()) q.push(-nc);
    }
    cout << ans << '\n';
}