#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int from, int by, int to){
    if(n > 2){
        hanoi(n-1, from, to, by);
        hanoi(1, from, by, to);
        hanoi(n-1, by, from, to);
    }
    else if(n == 2){
        hanoi(1, from, to, by);
        hanoi(1, from, by, to);
        hanoi(1, by, from, to);
    }
    else if(n == 1)
        cout<<from<<" "<<to<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    cout << (int)pow(2, n)-1 <<'\n';
    hanoi(n, 1, 2, 3);
}