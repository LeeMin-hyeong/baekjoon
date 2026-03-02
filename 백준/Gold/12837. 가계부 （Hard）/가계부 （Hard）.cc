#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, Q;

long long query(vector<long long> &tree, int node, int start, int end, int left, int right){
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

void update(vector<long long> &tree, int node, int start, int end, int target, int val){
    if(start == end){
        tree[node] += val;
    }
    else{
        if(target > (start+end)/2){
            update(tree, node*2+1, (start+end)/2+1, end, target, val);
        }
        else{
            update(tree, node*2, start, (start+end)/2, target, val);
        }
        tree[node] = tree[node*2] + tree[node*2+1];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> Q;
    int h = ceil(log2(N));
    vector<long long> tree(1LL << (h+1));
    for(int i=0; i<Q; i++){
        int a; cin >> a;
        if(a == 1){
            int p, x; cin >> p >> x;
            update(tree, 1, 1, N, p, x);
        }
        else{
            int p, q; cin >> p >> q;
            cout << query(tree, 1, 1, N, p, q) << '\n';
        }
    }
}
