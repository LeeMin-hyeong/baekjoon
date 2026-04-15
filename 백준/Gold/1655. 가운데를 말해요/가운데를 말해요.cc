#include <iostream>
#include <queue>
using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> r;
priority_queue<int> l;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        if (l.size() == r.size()) l.push(a);
        else r.push(a);

        if (!l.empty() && !r.empty() && l.top() > r.top()) {
            int lm = l.top(); l.pop();
            int rm = r.top(); r.pop();
            l.push(rm);
            r.push(lm);
        }
        cout << l.top() << '\n';
    }
}
