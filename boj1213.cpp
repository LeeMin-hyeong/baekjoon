#include <iostream>
using namespace std;

int alphabat[26];
int main(){
    string s;
    cin >> s;
    int n = s.size();
    char ans[n];
    for(int i=0; i<n; i++)
        alphabat[s[i]-'A']++;
    int cnt = 0;
    for(int i=0; i<26; i++)
        if(alphabat[i]%2 == 1) cnt++;
    if(cnt > 1) cout << "I'm Sorry Hansoo\n";
    else{
        int i=0;
        for(int j=0; j<26; j++){
            if(alphabat[j]>0){
                if(alphabat[j]%2 == 1){
                    ans[n/2] = j+'A';
                    alphabat[j]--;
                }
                while(alphabat[j]>0){
                    ans[i] = j+'A';
                    ans[n-i-1] = j+'A';
                    i+=1;
                    alphabat[j] -= 2;
                }
            }
        }
        for(int i=0; i<n; i++)
            cout << ans[i];
        cout << "\n";
    }
}