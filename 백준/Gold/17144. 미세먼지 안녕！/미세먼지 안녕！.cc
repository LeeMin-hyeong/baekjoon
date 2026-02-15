#include <bits/stdc++.h>
#define ROW first
#define COL second
using namespace std;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int room[51][51];
int r, c, t;
int c_top, c_bottom;

int ans(){
    int ans = 0;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(room[i][j] > 0) ans += room[i][j];
        }
    }
    return ans;
}

void spread(){
    vector<pair<pair<int, int>, int>> v;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            if(room[i][j] > 0){
                v.push_back({{i, j}, room[i][j]});
                room[i][j] = 0;
            }
        }
    }
    for(int i=0; i<v.size(); i++){
        int y = v[i].first.ROW;
        int x = v[i].first.COL;
        int dust = v[i].second;
        int cnt = 0;
        for(int j=0; j<4; j++){
            int ny = y+dy[j];
            int nx = x+dx[j];
            if(ny > 0 && ny <= r && nx > 0 && nx <= c && room[ny][nx] != -1){
                room[ny][nx] += dust/5;
                cnt++;
            }
        }
        room[y][x] += (dust - (dust/5)*cnt);
    }
}

void clean(){
    for(int y=c_top-1; y>1; y--){
        room[y][1] = room[y-1][1];
    }
    for(int x=1; x<c; x++){
        room[1][x] = room[1][x+1];
    }
    for(int y=1; y<c_top; y++){
        room[y][c] = room[y+1][c];
    }
    for(int x=c; x>2; x--){
        room[c_top][x] = room[c_top][x-1];
    }

    for(int y=c_bottom+1; y<r; y++){
        room[y][1] = room[y+1][1];
    }
    for(int x=1; x<c; x++){
        room[r][x] = room[r][x+1];
    }
    for(int y=r; y>c_bottom; y--){
        room[y][c] = room[y-1][c];
    }
    for(int x=c; x>2; x--){
        room[c_bottom][x] = room[c_bottom][x-1];
    }
    room[c_top][2] = 0;
    room[c_bottom][2] = 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c >> t;
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++){
            cin >> room[i][j];
        }
    }
    for(int i=1; i<=r; i++){
        if(room[i][1] == -1){
            c_top = i;
            c_bottom = i+1;
            break;
        }
    }
    while(t--){
        spread();
        clean();
    }
    cout << ans() << '\n';
}