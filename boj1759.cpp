#include <bits/stdc++.h>
using namespace std;

char a[15];
int l, c;
vector<string> v;

void gen(string s, int index, int len, int u, int t){
    if(len == l && u >=1 && t >=2){
        v.push_back(s);
        return;
    }
    for(int i=index; i<c; i++){
        string tmp = s;
        s += a[i];
        if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u')
            gen(s, i+1, len+1, u+1, t);
        else
            gen(s, i+1, len+1, u, t+1);
        s = tmp;
    }
}

int main(){
    cin >> l >> c;
    for(int i=0; i<c; i++){
        cin >> a[i];
    }
    sort(a, a+c);
    gen("", 0, 0, 0, 0);
    for(int i=0; i<v.size(); i++){
        cout << v[i] << '\n';
    }
}