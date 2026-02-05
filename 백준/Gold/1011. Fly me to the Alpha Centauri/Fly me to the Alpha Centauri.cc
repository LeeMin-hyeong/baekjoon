#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int start, end;
        cin >> start >> end;
        int dist = end-start;
        int max = (int)sqrt(dist);
        if(max == sqrt(dist)) cout << 2*max - 1 << "\n";
        else if(dist <= max*max+max) cout << 2*max << "\n";
        else cout << 2*max+1 << "\n";
    }
}