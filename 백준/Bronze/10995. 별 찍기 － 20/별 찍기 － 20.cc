#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<n*2+1; j++){
            if(i % 2 == 1){
                if(j % 2 == 1){
                    cout << '*';
                }
                else{
                    cout << ' ';
                }
            }
            else{
                if(j % 2 == 0){
                    cout << '*';
                }
                else{
                    cout << ' ';
                }
            }
        }
        cout << '\n';
    }
}