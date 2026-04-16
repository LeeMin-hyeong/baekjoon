#include <iostream>
#include <queue>
using namespace std;

int n;

struct compare{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};
priority_queue<int, vector<int>, compare> pq;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        if(x == 0){
            if(pq.empty()){
                cout << 0 << '\n';
                continue;
            }
            cout << pq.top() << '\n';
            pq.pop();
        }
        else{
            pq.push(x);
        }
    }
}
