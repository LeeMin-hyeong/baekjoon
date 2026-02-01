#include <bits/stdc++.h>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

typedef pair<int, int> p;

int room[50][50];

int N, M;
int n, m, d;
int ans;

queue<p> q;

void rotate(){
    d = (d+3) % 4;
}

bool check_clean(int y, int x){
    for(int i=0; i<4; i++){
        if(room[y+dy[i]][x+dx[i]] == 0){
            return true;
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    cin >> n >> m >> d;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> room[i][j];
        }
    }
    q.push(p(n, m));

    while(!q.empty()){
        p cur = q.front();
        int y = cur.first;
        int x = cur.second;
        q.pop();

        if(room[y][x] == 0){
            room[y][x] = 2;
            ans++;
        }
        if(check_clean(y, x)){
            for(int i=0; i<4; i++){
                rotate();
                if(room[y + dy[d]][x + dx[d]] == 0){
                    q.push(p(y + dy[d], x + dx[d]));
                    break;
                }
            }
        }
        else {
            if(room[y + dy[(d+2)%4]][x + dx[(d+2)%4]] != 1){
                q.push(p(y + dy[(d+2)%4], x + dx[(d+2)%4]));
            }
        }
    }
    cout << ans << '\n';
}