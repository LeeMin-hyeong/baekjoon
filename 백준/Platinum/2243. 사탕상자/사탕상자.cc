#include <bits/stdc++.h>
using namespace std;

int give(vector<int> &tree, int node, int start, int end, int grade){
    if(start == end){
        tree[node]--;
        return start;
    }
    int ret;

    if(tree[node*2] >= grade){
        ret = give(tree, node*2, start, (start+end)/2, grade);
    } else {
        ret = give(tree, node*2+1, (start+end)/2+1, end, grade - tree[node*2]);
    }

    tree[node] = tree[node*2] + tree[node*2+1];
    return ret;
}

void touch(vector<int> &tree, int node, int start, int end, int flavor, int amount){
    if(flavor < start || flavor > end) return;
    tree[node] += amount;
    if(start == end) return;
    if(flavor > (start+end)/2){
        touch(tree, node*2+1, (start+end)/2+1, end, flavor, amount);
    }
    else{
        touch(tree, node*2, start, (start+end)/2, flavor, amount);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    int h = (int)ceil(log2(1000000));
    vector<int> tree(1 << (h+1));

    for(int i=1; i<=n; i++){
        int a, b, c;
        cin >> a;
        if(a == 1){
            cin >> b;
            cout << give(tree, 1, 1, 1000000, b) << '\n';
        }
        else{
            cin >> b >> c;
            touch(tree, 1, 1, 1000000, b, c);
        }
    }
}