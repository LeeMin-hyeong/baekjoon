#include <bits/stdc++.h>
using namespace std;

int n;
int cave[125][125];
int cost[125][125];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};


int dijkstra(){
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({-cave[0][0], {0, 0}});
    cost[0][0] = cave[0][0];
    while(!pq.empty()){
        int w = -pq.top().first;
        int y = pq.top().second.first;
        int x = pq.top().second.second;
        pq.pop();

        if(w > cost[y][x]) continue;

        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny >= 0 && nx >= 0 && ny < n && nx < n){
                if(cost[ny][nx] > cost[y][x]+cave[ny][nx]){
                    cost[ny][nx] = cost[y][x]+cave[ny][nx];
                    pq.push({-cost[ny][nx], {ny, nx}});
                }
            }
        }
    }
    return cost[n-1][n-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int cnt = 0;
    while(++cnt){
        cin >> n;
        if(n == 0) break;
        memset(cave, 0, sizeof(cave));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cost[i][j] = 1e6;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> cave[i][j];
            }
        }
        cout << "Problem " << cnt << ": " << dijkstra() << '\n';
    }
}