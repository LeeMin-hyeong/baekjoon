#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, k;

void init(vector<int> &arr, vector<int> &tree, int node, int start, int end){
    if(start == end){
        tree[node] = arr[start];
    }
    else{
        init(arr, tree, node*2, start, (start+end)/2);
        init(arr, tree, node*2+1, (start+end)/2+1, end);
        long long val = (long long)tree[node*2] * tree[node*2+1];
        tree[node] = val % 1'000'000'007;
    }
}

int query(vector<int> &tree, int node, int start, int end, int left, int right){
    if(right < start || end < left){
        return 1;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    long long l_ret = query(tree, node*2, start, (start+end)/2, left, right);
    long long r_ret = query(tree, node*2+1, (start+end)/2+1, end, left, right);

    return (l_ret*r_ret) % 1'000'000'007;
}

void update(vector<int> &tree, int node, int target, int val, int start, int end){
    if(start == end){
        tree[node] = val;
    }
    else{
        if(target <= (start+end)/2){
            update(tree, node*2, target, val, start, (start+end)/2);
        }
        else{
            update(tree, node*2+1, target, val, (start+end)/2+1, end);
        }
        long long val = (long long)tree[node*2] * tree[node*2+1];
        tree[node] = val % 1'000'000'007;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    int h = ceil(log2(n));
    vector<int> tree(1<<(h+1));
    init(arr, tree, 1, 1, n);
    for(int i=0; i<m+k; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update(tree, 1, b, c, 1, n);
        }
        if(a == 2){
            cout << query(tree, 1, 1, n, b, c) << '\n';
        }
    }
}