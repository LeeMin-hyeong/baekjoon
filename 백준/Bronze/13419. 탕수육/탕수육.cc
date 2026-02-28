#include <iostream>
#include <cstring>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        if(s.length() % 2 == 0){
            for(int i=0; i<s.length(); i+=2){
                cout << s[i];
            }
            cout << '\n';
            for(int i=1; i<s.length(); i+=2){
                cout << s[i];
            }
            cout << '\n';
        }
        else{
            for(int i=0; i<s.length()*2; i+=2){
                cout << s[i%s.length()];
            }
            cout << '\n';
            for(int i=1; i<s.length()*2; i+=2){
                cout << s[i%s.length()];
            }
            cout << '\n';
        }
    }
}