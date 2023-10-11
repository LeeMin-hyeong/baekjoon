#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
vector<p> vw, vb;
bool chess[10][10];
int n, ans_w, ans_b;

bool promising(int y, int x){
    if(chess[y][x]) return false;
    for(int i=y, j=x; i<n&&j<n; i++, j++)
        if(chess[i][j]) return false;
    for(int i=y, j=x; i>=0&&j>=0; i--, j--)
        if(chess[i][j]) return false;
    for(int i=y, j=x; i<n&&j>=0; i++, j--)
        if(chess[i][j]) return false;
    for(int i=y, j=x; i>=0&&j<n; i--, j++)
        if(chess[i][j]) return false;
    return true;
}

void bishop_w(int n){
    ans_w = max(ans_w, n);
    for(int i=0; i<vw.size(); i++){
        if(promising(vw[i].first, vw[i].second)){
            chess[vw[i].first][vw[i].second] = true;
            bishop_w(n+1);
            chess[vw[i].first][vw[i].second] = false;
        }
    }
}

void bishop_b(int n){
    ans_b = max(ans_b, n);
    for(int i=0; i<vb.size(); i++){
        if(promising(vb[i].first, vb[i].second)){
            chess[vb[i].first][vb[i].second] = true;
            bishop_b(n+1);
            chess[vb[i].first][vb[i].second] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int a; cin >> a;
            if(a == 1){
                if((i+j)%2 == 0)
                    vw.push_back(p(i, j));
                else
                    vb.push_back(p(i, j));
            }
        }
    }
    bishop_b(0);
    bishop_w(0);
    cout << ans_w+ans_b << '\n';
}