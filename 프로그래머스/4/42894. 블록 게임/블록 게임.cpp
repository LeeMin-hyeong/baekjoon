#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[201];
int sum[50][50];

bool can_remove(int y, int x, vector<vector<int>> &board){
    int cur = board[y][x];
    int n = board[0].size();
    if(x-1 >= 0 && x+1 < n && y+1 < n){
        if(sum[y][x-1] == 0
          && sum[y][x+1] == 0
          && board[y+1][x-1] == cur
          && board[y+1][x] == cur
          && board[y+1][x+1] == cur){
            board[y][x] = 0;
            board[y+1][x-1] = 0;
            board[y+1][x] = 0;
            board[y+1][x+1] = 0;
            return true;
        }
    }
    if(x+1 < n && y+2 < n){
        if(sum[y+1][x+1] == 0
          && board[y+1][x] == cur
          && board[y+2][x] == cur
          && board[y+2][x+1] == cur){
            board[y][x] = 0;
            board[y+1][x] = 0;
            board[y+2][x] = 0;
            board[y+2][x+1] = 0;
            return true;
        }
    }
    if(x-1 >= 0 && y+2 < n){
        if(sum[y+1][x-1] == 0
          && board[y+1][x] == cur
          && board[y+2][x] == cur
          && board[y+2][x-1] == cur){
            board[y][x] = 0;
            board[y+1][x] = 0;
            board[y+2][x] = 0;
            board[y+2][x-1] = 0;
            return true;
        }

    }
    if(x-2 >= 0 && y+1 < n){
        if(sum[y][x-2] == 0
          && sum[y][x-1] == 0
          && board[y+1][x-2] == cur
          && board[y+1][x-1] == cur
          && board[y+1][x] == cur){
            board[y][x] = 0;
            board[y+1][x-2] = 0;
            board[y+1][x-1] = 0;
            board[y+1][x] = 0;
            return true;
        }
    }
    if(x+2 < n && y+1 < n){
        if(sum[y][x+1] == 0
          && sum[y][x+2] == 0
          && board[y+1][x] == cur
          && board[y+1][x+1] == cur
          && board[y+1][x+2] == cur){
            board[y][x] = 0;
            board[y+1][x] = 0;
            board[y+1][x+1] = 0;
            board[y+1][x+2] = 0;
            return true;
        }
    }
    return false;
}

void update_sum(vector<vector<int>> &board){
    int n = board[0].size();
    for(int i=0; i<n; i++){
        sum[0][i] = board[0][i];
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<n; j++){
            sum[i][j] = board[i][j]+sum[i-1][j];
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board[0].size();
    vector<pair<int, int>> v;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] != 0 && !visited[board[i][j]]){
                visited[board[i][j]] = true;
                v.push_back({i, j});
            }
        }
    }
    
    while(true){
        update_sum(board);
        vector<pair<int, int>> temp;
        bool updated = false;
        for(auto [y, x] : v){
            if(can_remove(y, x, board)){
                answer++;
                updated = true;
                continue;
            }
            temp.push_back({y, x});
        }
        v = temp;
        if(!updated) break;
    }
    return answer;
}