#include <bits/stdc++.h>
using namespace std;

int n;
int ino[100001], ino_idx[100001];
int pos[100001];

void recur(int ino_start, int ino_end, int pos_start, int pos_end){
    if(ino_start > ino_end || pos_start > pos_end) return;
    int root = pos[pos_end];
    cout << root << ' ';
    recur(ino_start, ino_idx[root]-1, pos_start, pos_start+ino_idx[root]-ino_start-1);
    recur(ino_idx[root]+1, ino_end, pos_start+ino_idx[root]-ino_start, pos_end-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> ino[i];
        ino_idx[ino[i]] = i;
    }
    for(int i=1; i<=n; i++){
        cin >> pos[i];
    }
    recur(1, n, 1, n);
    cout << '\n';
}