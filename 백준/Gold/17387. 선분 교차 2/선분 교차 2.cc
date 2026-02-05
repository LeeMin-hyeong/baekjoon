#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<long long, long long> p;
typedef pair<p, p> l;

int ccw(p p1, p p2, p p3){
    long long s = (p3.x-p1.x)*(p3.y-p2.y)-(p3.y-p1.y)*(p3.x-p2.x);
    if(s > 0) return 1;
    else if(s < 0) return -1;
    else return 0;
}

bool intersect(l l1, l l2){
    p p1 = l1.first;
    p p2 = l1.second;
    p p3 = l2.first;
    p p4 = l2.second;

    int p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    int p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (p1p2 == 0 && p3p4 == 0) {
        if (p1 > p2) swap(p2, p1);
        if (p3 > p4) swap(p3, p4);
        
        return p3 <= p2 && p1 <= p4;
    }
    
    return p1p2 <= 0 && p3p4 <= 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    p a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

    cout << intersect(l(a, b), l(c, d)) << '\n';
}