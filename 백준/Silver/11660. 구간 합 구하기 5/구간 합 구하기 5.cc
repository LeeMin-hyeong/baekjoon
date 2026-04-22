#include <iostream>
using namespace std;

int n, m;
int table[1025][1025];
int sum[1025][1025];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> table[i][j];
            sum[i][j] = table[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
        }
    }
    for(int i=0; i<m; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << sum[c][d]-sum[c][b-1]-sum[a-1][d]+sum[a-1][b-1] << '\n';
    }
}
