#include <bits/stdc++.h>
#define INF 2500
using namespace std;

typedef pair<int, int> p;
int lab[50][50];
int test[50][50];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int n, m;
vector<p> v, s;
vector< vector<p> > pos;

void solve(int index, int cnt){
    if(cnt == m){
        pos.push_back(s);
        return;
    }
    for(int i=index; i<v.size(); i++){
        s.push_back(v[i]);
        solve(i+1, cnt+1);
        s.pop_back();
    }
}

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> lab[i][j];
            if(lab[i][j] == 2)
                v.push_back(p(i, j));
        }
    }
    solve(0, 0);

    int ans = INF;
    for(int i=0; i<pos.size(); i++){
        memset(test, -1, sizeof(test));
        queue<p> q;
        for(int j=0; j<m; j++){
            q.push(pos[i][j]);
            test[pos[i][j].first][pos[i][j].second] = 0;
        }
        while(!q.empty()){
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int ny = y+dy[k];
                int nx = x+dx[k];
                if(ny>=0 && ny<n && nx>=0 && nx<n){
                    if(test[ny][nx] == -1 && lab[ny][nx] != 1){
                        test[ny][nx] = test[y][x] + 1;
                        q.push(p(ny, nx));
                    }
                }
            }
        }
        int time = 0;
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(test[j][k] == -1 && lab[j][k] != 1) time = INF;
                time = max(time, test[j][k]);
            }
        }
        ans = min(ans, time);
    }
    if(ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
}