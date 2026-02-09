#include <bits/stdc++.h>
using namespace std;

void update(vector<long long> &tree, long long node, long long start, long long end, long long target, long long value){
    if(start == end && start == target){
        tree[node] = value;
    }
    else{
        if(target > (start+end)/2){
            update(tree, node*2+1, (start+end)/2+1, end, target, value);
        }
        else{
            update(tree, node*2, start, (start+end)/2, target, value);
        }
        tree[node] = tree[node*2]+tree[node*2+1];
    }
}

long long query(vector<long long> &tree, long long node, long long start, long long end, long long left, long long right){
    if(right < start || end < left){
        return 0;
    }
    if(left <= start && end <= right){
        return tree[node];
    }
    long long l_ret = query(tree, node*2, start, (start+end)/2, left, right);
    long long r_ret = query(tree, node*2+1, (start+end)/2+1, end, left, right);

    return l_ret+r_ret;
}

void init(vector<long long> &arr, vector<long long> &tree, long long node, long long start, long long end){
    if(start == end){
        tree[node] = arr[start];
    }
    else{
        init(arr, tree, node*2, start, (start+end)/2);
        init(arr, tree, node*2+1, (start+end)/2+1, end);
        tree[node] = tree[node*2]+tree[node*2+1];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> arr(n+1);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
    long long h = (long long)ceil(log2(n));
    vector<long long> tree(1LL << (h+1));
    init(arr, tree, 1, 1, n);
    for(int i=0; i<m+k; i++){
        long long a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update(tree, 1, 1, n, b, c);
        }
        else{
            cout << query(tree, 1, 1, n, b, c) << '\n';
        }
    }
}