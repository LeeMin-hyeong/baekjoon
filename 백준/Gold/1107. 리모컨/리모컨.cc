#include <bits/stdc++.h>
using namespace std;

bool broken[10];

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  int a; cin >> a;
  while(a--){
    int b; cin >> b;
    broken[b] = true;
  }

  int ans = abs(n-100);
  for(int i = 0; i <= 1000000; i++){
    string temp = to_string(i);
    bool cont = false;
    for(int j = 0; j < temp.size(); j++){
      if(broken[temp[j]-'0']){
        cont = true;
        break;
      }
    }
    if(cont) continue;
    ans = min(ans, (int)temp.size() + abs(i - n));
  }
  cout << ans << '\n';
}