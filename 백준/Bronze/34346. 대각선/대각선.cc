#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    if(n % 2 == 0) cout << 2 << '\n';
    else cout << 1 << '\n';
}