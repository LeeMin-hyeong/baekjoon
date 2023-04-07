#include <iostream>
using namespace std;

int paper_cnt[3];
int paper[2187][2187];
void cut(int x, int y, int k){
    int temp = paper[x][y];
    bool no_cut = true;
    for(int i=x; i<x+k; i++)
        for(int j=y; j<y+k; j++)
            if(temp!=paper[i][j])
                no_cut = false;
    if(no_cut) paper_cnt[temp+1]++;
    else{
        k /= 3;
        cut(x, y, k);
        cut(x+k, y, k);
        cut(x+2*k, y, k);
        cut(x, y+k, k);
        cut(x+k, y+k, k);
        cut(x+2*k, y+k, k);
        cut(x, y+2*k, k);
        cut(x+k, y+2*k, k);
        cut(x+2*k, y+2*k, k);
    }
}
int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> paper[i][j];
    cut(0, 0, n);
    cout << paper_cnt[0] << "\n" << paper_cnt[1] << "\n" << paper_cnt[2] << "\n";
}