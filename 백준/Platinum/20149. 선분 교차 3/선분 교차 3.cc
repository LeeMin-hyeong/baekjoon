#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<long double, long double> point;
typedef pair<point, point> line;

int ccw(point p1, point p2, point p3){
    long double s = (p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
    if(s > 0) return 1;
    else if(s < 0) return -1;
    else return 0;
}

bool intersect(line l1, line l2){
    point p1 = l1.first;
    point p2 = l1.second;
    point p3 = l2.first;
    point p4 = l2.second;

    long long p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4);
    long long p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2);

    if (p1p2 == 0 && p3p4 == 0) {
        if (p1 > p2) swap(p1, p2);
        if (p3 > p4) swap(p3, p4);
        
        return p3 <= p2 && p1 <= p4;
    }
    
    return p1p2 <= 0 && p3p4 <= 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;

    if(intersect(line(a, b), line(c, d))){
        cout << 1 << '\n';
        long double div = ((a.x-b.x)*(c.y-d.y)-(a.y-b.y)*(c.x-d.x));
        if(div == 0){
            point p1 = a, p2 = b, p3 = c, p4 = d;
            if (p2 < p1) swap(p1, p2);
            if (p4 < p3) swap(p3, p4);

            point s = max(p1, p3);
            point e = min(p2, p4);

            if (s == e) {
                cout << s.x << ' ' << s.y << '\n';
            }
        }
        else{
            long double px = (long double)((a.x*b.y-a.y*b.x)*(c.x-d.x) - (a.x-b.x)*(c.x*d.y-c.y*d.x))/div;
            long double py = (long double)((a.x*b.y-a.y*b.x)*(c.y-d.y) - (a.y-b.y)*(c.x*d.y-c.y*d.x))/div;
            printf("%.9Lf %.9Lf\n", px, py);
        }
    }
    else cout << 0 << '\n';
}