#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, x1, y1, x2, y2, r1, r2;
    cin>>n;
    for(int i=0; i<n; i++){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        long double dist = pow(x2-x1, 2) + pow(y2-y1, 2);
        long double rad = pow(r1+r2, 2);

        if(pow(r1, 2) > dist && pow(r2, 2) > dist){
            if(dist == rad) cout << "1\n";
            else if(dist < rad) cout << "2\n";
            else cout << "0\n";
        }
        else{
            if(dist == rad) cout << "1\n";
            else if(dist < rad) cout << "2\n";
            else cout << "0\n";
        }
    }
}