#include <bits/stdc++.h>
using namespace std;

int n, m;
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
int board[11][11];
int island[11][11];
int parent[7];
int cnt = 1;
int ans;
priority_queue<pair<int, pair<int, int>>> pq;
vector<pair<int, int>> v;

int find(int p){
    if(p == parent[p]) return p;
    else return parent[p] = find(parent[p]);
}

bool union_find(int p, int q){
    int pp = find(p);
    int pq = find(q);
    if(pp == pq) return false;
    if(pq < pp) parent[pq] = pp;
    else parent[pp] = pq;
    return true;
}

void group(int i, int j){
    queue<pair<int, int>> q;
    q.push({i, j});
    island[i][j] = cnt;

    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        bool edge_flag = false;
        for(int k=0; k<4; k++){
            int ny = y+dy[k];
            int nx = x+dx[k];
            if(ny > 0 && nx > 0 && ny <= n && nx <= m){
                if(board[ny][nx] == 1){
                    if(island[ny][nx] == 0){
                        island[ny][nx] = cnt;
                        q.push({ny, nx});
                    }
                }
                else{
                    edge_flag = true;
                }
            }
        }
        if(edge_flag){
            v.push_back({y, x});
        }
    }
    cnt++;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> board[i][j];
        }
    }
    // group island
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(island[i][j] == 0 && board[i][j] != 0){
                group(i, j);
            }
        }
    }
    // find possible bridges
    for(int i=0; i<v.size(); i++){
        int y = v[i].first;
        int x = v[i].second;
        int from = island[y][x];
        int to;
        for(int j=0; j<4; j++){
            int w;
            bool bridge = false;
            for(w=1; w<=10; w++){
                int ny = y + w * dy[j];
                int nx = x + w * dx[j];
                if(ny > 0 && nx > 0 && ny <= n && nx <= m){
                    if(island[ny][nx] > 0){
                        to = island[ny][nx];
                        bridge = true;
                        break;
                    }
                }
            }
            if(bridge && w > 2){
                pq.push({-(w-1), {from, to}});
            }
        }
    }
    for(int i=1; i<cnt; i++){
        parent[i] = i;
    }
    int edge_cnt = 0;
    while(!pq.empty()){
        int w = -pq.top().first;
        int p = pq.top().second.first;
        int q = pq.top().second.second;
        pq.pop();
        if(union_find(p, q)){
            ans += w;
            edge_cnt++;
        }
    }
    if(edge_cnt != cnt-2){
        cout << -1 << '\n';
    }
    else{
        cout << ans << '\n';
    }
}
