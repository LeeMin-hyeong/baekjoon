#include <iostream>
using namespace std;
bool chess[15][15];
int n, ans;

bool promising(int y, int x){
    for(int i=0; i<n; i++){
        if(chess[y][i]) return false;
        if(chess[i][x]) return false;
    }
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
void queen(int a){
    if(a == n){
        ans++;
        return;
    }
    for(int i=0; i<n; i++){
        if(promising(a, i)){
            chess[a][i] = true;
            queen(a+1);
            chess[a][i] = false;
        }
    }
}

int main(){
    cin >> n;
    queen(0);
    cout << ans << '\n';
}