#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int cnt = 0;
    int temp = 666;
    int ans;
    while(cnt < n){
        string s = to_string(temp);
        for(int i=0; i<s.size()-2; i++){
            if(s[i] == '6' && s[i+1] == '6' && s[i+2] == '6'){
                if(++cnt == n){
                    ans = temp;
                }
                break;
            }
        }
        temp++;
    }
    cout << ans << '\n';
}