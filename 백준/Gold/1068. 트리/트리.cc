#include <bits/stdc++.h>
using namespace std;


int N, D, root, ans;
vector<int> tree[51];

void dfs(int x){
  if(x == D) return;
  else if(tree[x].size() == 0) ans++;
  else if(tree[x].size() == 1 && tree[x][0] == D) ans++;
  else{
    for(int i=0; i<tree[x].size(); i++){
      dfs(tree[x][i]);
    }
  }
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for(int i=0; i<N; i++){
    int a; cin >> a;
    if(a == -1) root = i;
    else tree[a].push_back(i);
  }

  cin >> D;

  dfs(root);

  cout << ans << '\n';
}