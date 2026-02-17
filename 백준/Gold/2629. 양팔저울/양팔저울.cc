#include <bits/stdc++.h>
using namespace std;

int n, k;
bool checkable[40001];
vector<int> v;

int main(){
    cin >> n;
    int max_w = 0;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        max_w += a;
        queue<int> q;
        q.push(a);
        for(int j=1; j<=max_w; j++){
            if(checkable[j]){
                q.push(abs(j-a));
                q.push(j+a);
            }
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            checkable[x] = true;
        }
    }
    cin >> k;
    for(int i=0; i<k; i++){
        int a; cin >> a;
        if(checkable[a]){
            cout << "Y ";
        }
        else{
            cout << "N ";
        }
    }
    cout << '\n';
}