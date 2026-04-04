#include <iostream>
#include <cstring>
using namespace std;

bool prime[250000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i=2; i<250000; i++){
        if(prime[i]){
            for(int j=2; i*j<250000; j++){
                prime[i*j] = false;
            }
        }
    }
    while(true){
        int n; cin >> n;
        if(n == 0) break;
        int cnt = 0;
        for(int i=n+1; i<=2*n; i++){
            if(prime[i]) cnt++;
        }
        cout << cnt << '\n';
    }
}