#include <bits/stdc++.h>
using namespace std;

char temp;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int TC;
    cin >> TC;
    while(TC--){
        bool error = false, r = false;

        string command; cin >> command;
        int n; cin >> n;

        deque<int> v;
        cin >> temp;
        for(int i=0; i<n; i++){
            int k; cin >> k;
            v.push_back(k);
            if(i < n-1){
                cin >> temp;
            }
        }
        cin >> temp;
        
        for(int i=0; i<command.length(); i++){
            if(command[i] == 'R'){
                r = !r;
            }
            else{
                if(v.empty()){
                    error = true;
                    break;
                }
                if(r) v.pop_back();
                else v.pop_front();
            }
        }
        if(error) cout << "error\n";
        else{
            cout << '[';
            for(int i=0; i<v.size(); i++){
                if(r) cout << v[v.size()-i-1];
                else cout << v[i];
                if(i != v.size()-1) cout << ',';
            }
            cout << "]\n";
        }
    }
}