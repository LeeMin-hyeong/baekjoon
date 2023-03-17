#include <iostream>
using namespace std;

long double factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c, n, m;
    cin>>c;
    for(int i=0; i<c; i++){
        cin >> n >> m;
        printf("%.0Lf\n", factorial(m) / (factorial(n) * factorial(m - n)));
    }
}   
