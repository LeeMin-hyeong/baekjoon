#include <bits/stdc++.h>
using namespace std;

int n, k;
long long ans;
typedef pair<int, int> gem;
priority_queue<gem> gems;
priority_queue<int> bag;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int m, v;
        cin >> m >> v;
        gems.push(gem(-m, v));
    }
    for(int i=0; i<k; i++){
        int c;
        cin >> c;
        bag.push(-c);
    }
    priority_queue<int> candidate;
    while(!bag.empty()){
        int c = -bag.top();
        bag.pop();

        while(!gems.empty() && -gems.top().first <= c){
            candidate.push(gems.top().second);
            gems.pop();
        }

        if(!candidate.empty()){
            ans += candidate.top();
            candidate.pop();
        }
    }
    cout << ans << '\n';
}