#include <bits/stdc++.h>
using namespace std;
#define MAX first
#define MIN second

int num[100001];
int n, m;

void init(vector<int> &arr, vector<pair<int, int>> &tree, int node, int start, int end){
    if(start == end){
        tree[node] = {num[start], num[start]};
    }
    else{
        init(arr, tree, node*2, start, (start+end)/2);
        init(arr, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = {max(tree[node*2].MAX, tree[node*2+1].MAX), min(tree[node*2].MIN, tree[node*2+1].MIN)};
    }
}

pair<int, int> query(vector<pair<int, int>> &tree, int node, int start, int end, int left, int right){
    if(left > end || right < start){
        return {0, 1000000001};
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    pair<int, int> l_ret = query(tree, node*2, start, (start+end)/2, left, right);
    pair<int, int> r_ret = query(tree, node*2+1, (start+end)/2+1, end, left, right);
    return {max(l_ret.MAX, r_ret.MAX), min(l_ret.MIN, r_ret.MIN)};
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    vector<int> arr(n+1);
    int h = (int)ceil(log2(n));
    vector<pair<int, int>> tree(1 << (h+1));
    for(int i=1; i<=n; i++){
        cin >> num[i];
    }
    init(arr, tree, 1, 1, n);
    for(int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        pair<int, int> p = query(tree, 1, 1, n, a, b);
        cout << p.MIN << ' ' << p.MAX << '\n';
    }
}