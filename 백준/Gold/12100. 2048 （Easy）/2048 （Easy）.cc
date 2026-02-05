#include <bits/stdc++.h>
using namespace std;

int n, ans;
typedef vector< vector<int> > vv;
bool check[20][20];

vv left(vv board){
    memset(check, false, sizeof(check));
    for (int i=0; i<n; i++){
        for (int j=1; j<n; j++){
            if (board[i][j] == 0)
                continue;
            for (int k=j-1; k>=0; k--){
                if (board[i][k] == board[i][k+1] && !check[i][k]){
                    board[i][k] *= 2;
                    board[i][k+1] = 0;
                    check[i][k] = true;
                    break;
                }
                else if (board[i][k] == 0){
                    board[i][k] = board[i][k+1];
                    board[i][k+1] = 0;
                }
                else break;
            }
        }
    }
    return board;
}
vv right(vv board){
    memset(check, false, sizeof(check));
    for (int i=0; i<n; i++){
        for (int j=n-2; j>=0; j--){
            if (board[i][j] == 0)
                continue;
            for (int k=j+1; k<n; k++){
                if (board[i][k] == board[i][k-1] && !check[i][k]){
                    board[i][k] *= 2;
                    board[i][k-1] = 0;
                    check[i][k] = true;
                    break;
                }
                else if (board[i][k] == 0){
                    board[i][k] = board[i][k-1];
                    board[i][k-1] = 0;
                }
                else break;
            }
        }
    }
    return board;
}
vv up(vv board){
    memset(check, false, sizeof(check));
    for (int i=0; i<n; i++){
        for (int j=1; j<n; j++){
            if (board[j][i] == 0)
                continue;
            for (int k=j-1; k>=0; k--){
                if (board[k][i] == board[k+1][i] && !check[k][i]){
                    board[k][i] *= 2;
                    board[k+1][i] = 0;
                    check[k][i] = true;
                    break;
                }
                else if (board[k][i] == 0){
                    board[k][i] = board[k+1][i];
                    board[k+1][i] = 0;
                }
                else break;
            }
        }
    }
    return board;
}
vv down(vv board){
    memset(check, false, sizeof(check));
    for (int i=0; i<n; i++){
        for (int j=n-2; j>=0; j--){
            if (board[j][i] == 0)
                continue;
            for (int k=j+1; k<n; k++){
                if (board[k][i] == board[k-1][i] && !check[k][i]){
                    board[k][i] *= 2;
                    board[k-1][i] = 0;
                    check[k][i] = true;
                    break;
                }
                else if (board[k][i] == 0){
                    board[k][i] = board[k-1][i];
                    board[k-1][i] = 0;
                }
                else break;
            }
        }
    }
    return board;
}


int check_board(vv board){
    int ret = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ret = max(ret, board[i][j]);
        }
    }
    return ret;
}

void backtracking(int cnt, vv board){
    ans = max(ans, check_board(board));
    if(cnt < 5){
        backtracking(cnt+1, left(board));
        backtracking(cnt+1, right(board));
        backtracking(cnt+1, up(board));
        backtracking(cnt+1, down(board));
    }
}

int main(){
    cin >> n;
    vv board;
    for(int i=0; i<n; i++){
        vector<int> v;
        for(int j=0; j<n; j++){
            int a; cin >> a;
            v.push_back(a);
        }
        board.push_back(v);
    }
    backtracking(0, board);
    cout << ans << '\n';
}