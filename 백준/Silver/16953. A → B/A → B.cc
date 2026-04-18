#include <iostream>
using namespace std;

int a, b, cnt = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    while(b > a) {
        if (b % 10 == 1) {
            b /= 10;
        } else if (b % 2 == 0) {
            b /= 2;
        } else {
            break;
        }
        cnt++;
    }
    cout << (b == a ? cnt : -1) << '\n';
}
