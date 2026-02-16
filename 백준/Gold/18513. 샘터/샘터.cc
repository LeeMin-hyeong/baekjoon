#include <bits/stdc++.h>
using namespace std;

int n, k;
unordered_map<int, bool> o;
queue<pair<int, int>> q;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        q.push({a, 0});
        o[a] = true;
    }
    int cnt = 0;
    long long ans = 0;
    while(cnt < k){
        int loc = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(!o[loc-1]){
            q.push({loc-1, dist+1});
            o[loc-1] = true;
            cnt++;
            ans += dist+1;
        }
        if(cnt == k) break;
        if(!o[loc+1]){
            q.push({loc+1, dist+1});
            o[loc+1] = true;
            cnt++;
            ans += dist+1;
        }
    }
    cout << ans << '\n';
}