#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
char building[102][102];
bool visited[102][102];
bool key[26];
vector<p> door[26];
int dy[] = {1, 0, -1, 0}, dx[] = {0, 1, 0, -1};
int tc, h, w;

int steal(){
    int cnt = 0;
    memset(visited, false, sizeof(visited));
    queue<p> q;
    q.push(p(0, 0));
    visited[0][0] = true;
    while(!q.empty()){
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny >= 0 && ny <= h+1 && nx >=0 && nx <= w+1){
                if(building[ny][nx] == '*') continue;
                if(!visited[ny][nx]){
                    visited[ny][nx] = true;
                    if(building[ny][nx] >= 'A' && building[ny][nx] <= 'Z'){
                        if(key[building[ny][nx]-'A']){
                            q.push(p(ny, nx));
                        }
                        else{
                            door[building[ny][nx]-'A'].push_back(p(ny, nx));
                        }
                    }
                    else if(building[ny][nx] >= 'a' && building[ny][nx] <= 'z'){
                        if(!key[building[ny][nx]-'a']){
                            key[building[ny][nx]-'a'] = true;
                            for(int i=0; i<door[building[ny][nx]-'a'].size(); i++){
                                q.push(door[building[ny][nx]-'a'][i]);
                            }
                            door[building[ny][nx]-'a'].clear();
                        }
                        q.push(p(ny, nx));
                    }
                    else if(building[ny][nx] == '$'){
                        q.push(p(ny, nx));
                        cnt++;
                    }
                    else if(building[ny][nx] == '.')
                        q.push(p(ny, nx));
                }
            }
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while(tc--){
        cin >> h >> w;
        for(int i=0; i<=h+1; i++){
            for(int j=0; j<=w+1; j++){
                if(i == 0 || j == 0 || i == h+1 || j == w+1)
                    building[i][j] = '.';
                else
                    cin >> building[i][j];
            }
        }
        memset(key, false, sizeof(key));
        string keys; cin >> keys;
        if(keys[0] != '0'){
            for(int i=0; i<keys.length(); i++){
                key[keys[i]-'a'] = true;
            }
        }
        for(int i=0; i<26; i++){
            door[i].clear();
        }
        cout << steal() << '\n';
    }
}