#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

int n;
typedef pair<long double, long double> p;
vector<p> pts;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        pts.push_back(p(x, y));
    }
    long double ans = 0;
    int j = n-1;
    for(int i=0; i<n; i++){
        ans += (pts[j].x+pts[i].x)*(pts[j].y-pts[i].y)/2;
        j = i;
    }
    printf("%.1Lf\n", abs(ans));
}