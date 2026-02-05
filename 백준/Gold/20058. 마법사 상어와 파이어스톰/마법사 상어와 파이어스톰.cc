#include <bits/stdc++.h>
using namespace std;

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int ice[64][64];
bool visited[64][64];
int n, q;
int temp[64][64];

void print_ice(){
    for(int i=0; i<1<<n; i++){
        for(int j=0; j<1<<n; j++){
            cout << ice[i][j] << ' ';
        }
        cout << '\n';
    }
}

void tornado(int l){
    int S = 1 << n;
    int L = 1 << l;

    for(int i = 0; i < S; i += L){
        for(int j = 0; j < S; j += L){
            for(int y = 0; y < L; y++){
                for(int x = 0; x < L; x++){
                    temp[i + x][j + (L - 1 - y)] = ice[i + y][j + x];
                }
            }
        }
    }

    for(int i=0; i<S; i++){
        for(int j=0; j<S; j++){
            ice[i][j] = temp[i][j];
        }
    }
}

void melt(){
    queue<pair<int, int>> q;
    for(int i=0; i<1<<n; i++){
        for(int j=0; j<1<<n; j++){
            if(ice[i][j] > 0){
                int cnt = 0;
                for(int k=0; k<4; k++){
                    int ny = i+dy[k];
                    int nx = j+dx[k];
                    if(ny >= 0 && ny < 1<<n && nx >= 0 && nx < 1<<n){
                        if(ice[ny][nx] > 0) cnt++;
                    }
                }
                if(cnt < 3){
                    q.push({i, j});
                }
            }
        }
    }
    while(!q.empty()){
        ice[q.front().first][q.front().second]--;
        q.pop();
    }
}

int ice_sum(){
    int sum = 0;
    for(int i=0; i<1<<n; i++){
        for(int j=0; j<1<<n; j++){
            sum += ice[i][j];
        }
    }
    return sum;
}

int biggest_ice(){
    int ret = 0;
    memset(visited, false, sizeof(visited));

    for(int i=0; i<1<<n; i++){
        for(int j=0; j<1<<n; j++){
            if(!visited[i][j] && ice[i][j] > 0){
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                int cnt = 0;

                while(!q.empty()){
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    cnt++;

                    for(int k=0; k<4; k++){
                        int ny = y+dy[k];
                        int nx = x+dx[k];
                        if(ny >= 0 && ny < 1<<n && nx >= 0 && nx < 1<<n){
                            if(!visited[ny][nx] && ice[ny][nx] > 0){
                                visited[ny][nx] = true;
                                q.push({ny, nx});
                            }
                        }
                    }
                }
                ret = max(ret, cnt);
            }
        }
    }

    return ret;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for(int i=0; i<1<<n; i++){
        for(int j=0; j<1<<n; j++){
            cin >> ice[i][j];
        }
    }
    for(int i=0; i<q; i++){
        int a; cin >> a;
        if(a != 0) tornado(a);
        melt();
    }
    // print_ice();
    cout << ice_sum() << '\n';
    cout << biggest_ice() << '\n';
}