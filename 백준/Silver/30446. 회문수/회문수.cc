#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.length();

    long long cnt = 0;
    for(int i=1; i<=n; i++){
        if(i%2 == 0){
            for(int j=(int)pow(10, i/2-1); j<(int)pow(10, i/2); j++){
                string tmp = to_string(j);
                reverse(tmp.begin(), tmp.end());
                long long palindrome = stol(to_string(j).append(tmp));
                if(palindrome <= stol(s)){
                    // cout << palindrome << '\n';
                    cnt++;
                }
            }
        }
        else{
            for(int j=(int)pow(10, i/2); j<(int)pow(10, i/2+1); j++){
                string tmp = to_string(j);
                tmp.pop_back();
                reverse(tmp.begin(), tmp.end());
                long long palindrome = stol(to_string(j).append(tmp));
                if(palindrome <= stol(s)){
                    // cout << palindrome << '\n';
                    cnt++;
                }
            }
        }
    }
    cout << cnt << '\n';
}