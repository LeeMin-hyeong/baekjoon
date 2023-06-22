#include <bits/stdc++.h>
using namespace std;

int lab[8][8];
bool visited[8][8];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int n, m, w;
typedef pair<int, int> p;
vector<p> z, v;


int bfs(){
    memset(visited, false, sizeof(visited));
    int cnt = v.size();
    queue<p> q;
    for(int i=0; i<v.size(); i++)
        q.push(v[i]);
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int ny = y+dy[k];
            int nx = x+dx[k];
            if(ny>=0 && ny<n && nx>=0 && nx<m){
                if(lab[ny][nx] == 0){
                    if(!visited[ny][nx]){
                        visited[ny][nx] = true;
                        q.push(p(ny, nx));
                        cnt++;
                    }
                }
            }
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> lab[i][j];
            if(lab[i][j] == 0)
                z.push_back(p(i, j));
            else if(lab[i][j] == 2)
                v.push_back(p(i, j));
            else w++;
        }
    }
    int min_v = 65;
    for(int i=0; i<z.size(); i++){
        for(int j=i+1; j<z.size(); j++){
            for(int k=j+1; k<z.size(); k++){
                lab[z[i].first][z[i].second] = 2;
                lab[z[j].first][z[j].second] = 2;
                lab[z[k].first][z[k].second] = 2;

                min_v = min(min_v, bfs());

                lab[z[i].first][z[i].second] = 0;
                lab[z[j].first][z[j].second] = 0;
                lab[z[k].first][z[k].second] = 0;
            }
        }
    }
    cout << n*m - min_v - w - 3 << '\n';
}