#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<long long, long long> p;
vector<p> v;
p pin;
int n;

bool left_below(p a, p b){
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

bool ccw_sort(p a, p b){
    double p1 = atan2(a.y-pin.y, a.x-pin.x);
    double p2 = atan2(b.y-pin.y, b.x-pin.x);
    if(p1 == p2){
        if(a.y == b.y) return a.x < b.x;
        else if(a.x == b.x) return a.y > b.y;
    }
    return p1 < p2;
}

long long ccw(p a, p b, p c){
    return (c.x-a.x)*(c.y-b.y)-(c.y-a.y)*(c.x-b.x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        v.push_back(p(a, b));
    }
    sort(v.begin(), v.end(), left_below);
    pin = v[0];
    sort(v.begin()+1, v.end(), ccw_sort);

    vector<p> s;
    s.push_back(v[0]);
    s.push_back(v[1]);
    for(int i=2; i<v.size(); i++){
        while(s.size() >= 2){
            int index = s.size();
            if(ccw(s[index-2], s[index-1], v[i]) == 0){
                s.pop_back();
                s.push_back(v[i]);
                break;
            }
            else if(ccw(s[index-2], s[index-1], v[i]) > 0){
                s.push_back(v[i]);
                break;
            }
            else{
                s.pop_back();
            }
        }
    }
    while(s.size() >= 2){
        int index = s.size();
        if(ccw(s[index-2], s[index-1], pin)>0) break;
        else s.pop_back();
    }
    cout << s.size() << '\n';
}