#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef pair<long long, long long> p;
vector<p> v;
p pin;
int n;

bool left_below(p a, p b){
    if(a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool ccw_sort(p a, p b){
    long long l = (b.x - pin.x) * (a.y - pin.y);
	long long r = (a.x - pin.x) * (b.y - pin.y);
	if (l != r) return l < r;
	
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

long long ccw(p a, p b, p c){
    return (c.x-a.x)*(c.y-b.y)-(c.y-a.y)*(c.x-b.x);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b; char c; cin >> a >> b >> c;
        if(c == 'Y')
            v.push_back(p(a, b));
    }
    sort(v.begin(), v.end(), left_below);
    pin = v[0];
    sort(v.begin()+1, v.end(), ccw_sort);

    cout << v.size() << '\n';
    int s = v.size()-1;
    for(; s>0; s--){
        if(ccw(pin, v[s], v[s-1]) != 0) break;
    }
    reverse(v.begin()+s, v.end());
    for(int i=0; i<v.size(); i++)
        cout << v[i].x << ' ' << v[i].y << '\n';
}