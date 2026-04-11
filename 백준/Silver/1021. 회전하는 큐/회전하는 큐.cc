#include <iostream>
#include <algorithm>
#include <deque>
#include <cmath>
using namespace std;

int n, m, cnt;
deque<int> dq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        dq.push_back(i);
    }
    for(int i=0; i<m; i++){
        int a; cin >> a;
        while(true){
            int loc = find(dq.begin(), dq.end(), a)-dq.begin();
            if(loc == 0){
                dq.pop_front();
                n--;
                break;
            }
            if(loc > n/2){
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
            else{
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}
