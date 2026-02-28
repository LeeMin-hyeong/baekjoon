#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
int n;
vector<p> line;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        line.push_back({x, y});
    }
    sort(line.begin(), line.end());

    int ans = 0;
    int start = line[0].first;
    int end = line[0].second;
    for(int i=1; i<n; i++){
        int s = line[i].first;
        int e = line[i].second;
        if(s <= end && e > end){
            end = e;
        }
        else if(s > end){
            ans += end-start;
            start = s;
            end = e;
        }
    }
    ans += end-start;

    cout << ans << '\n';
}