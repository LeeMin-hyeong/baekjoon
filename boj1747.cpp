#include <iostream>
#define MAX 2000000
using namespace std;

bool prime[MAX];

bool is_palindrome(int n){
    string pal = to_string(n);
    for(int j=0; j<pal.length()/2; j++){
        if(pal[j] != pal[pal.length()-1-j])
            return false;
    }
    return true;
}

int main(){
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for(int i=2; i<MAX; i++){
        for(int j=2; i*j<MAX; j++){
            if(prime[i]) prime[i*j] = false;
        }
    }
    int n;
    cin >> n;
    for(int i=n; i<MAX; i++){
        if(!prime[i]) continue;
        if(is_palindrome(i)){
            cout << i << "\n";
            break;
        }
    }
}