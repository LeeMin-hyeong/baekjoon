#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> l;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        l.push_back(x);
    }
    sort(l.begin(), l.end());
    int pt1 = 0, pt2 = n-1, ans = 2'000'000'001, ans1, ans2;
    while(pt1 < pt2){
        int flask = l[pt1] + l[pt2];
        if(abs(flask) < ans){
            ans = abs(flask);
            ans1 = l[pt1];
            ans2 = l[pt2];
        }
        if(flask >= 0){
            pt2--;
        }
        else{
            pt1++;
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
}