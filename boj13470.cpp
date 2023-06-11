#include <bits/stdc++.h>
using namespace std;

bool visited[101];
int parent[101];
typedef pair<int, int> p;
vector<p> s, t;
int n;

bool dfs(int i, int k){
    if(visited[i]) return false;
    visited[i] = true;
    for(int j=0; j<n; j++){
        if(abs(s[i].first-t[j].first)+abs(s[i].second-t[j].second) > k) continue;
        if(parent[j] == -1 || dfs(parent[j], k)){
            parent[j] = i;
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        s.push_back(p(x, y));
    }
    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        t.push_back(p(x, y));
    }
    int high = 2000000000, low = 0, ans;
    while(high>=low){
        int mid = (high+low)/2, cnt = 0;
        memset(parent, -1, sizeof(parent));
        for(int i=0; i<n; i++){
            memset(visited, false, sizeof(visited));
            if(dfs(i, mid)) cnt++;
        }
        if(cnt == n){
            ans = mid;
            high = mid-1;
        }
        else low = mid+1;
    }
    cout << ans << '\n'; 
}