#include <iostream>
#include <algorithm>
#include <deque>
#include <unordered_map>
using namespace std;

int n, k, l, d = 1;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
bool body[101][101];
bool apple[101][101];
deque<pair<int, int>> dummy;
unordered_map<int, char> timeline;

bool move(){
    int ny = dummy.back().first + dy[d];
    int nx = dummy.back().second + dx[d];
    if(ny <= n && nx <= n && ny > 0 && nx > 0 && !body[ny][nx]){
        if(!apple[ny][nx]){
            int tail_y = dummy.front().first;
            int tail_x = dummy.front().second;
            body[tail_y][tail_x] = false;
            dummy.pop_front();
        }
        dummy.push_back({ny, nx});
        apple[ny][nx] = false;
        body[ny][nx] = true;
        return true;
    }
    return false;
}

void rotate(char c){
    if(c == 'L'){
        d = (d+3)%4;
    }
    else if(c == 'D'){
        d = (d+1)%4;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0; i<k; i++){
        int y, x; cin >> y >> x;
        apple[y][x] = true;
    }
    cin >> l;
    dummy.push_back({1, 1});
    body[1][1] = true;
    for(int i=0; i<l; i++){
        int x; char c;
        cin >> x >> c;
        timeline[x] = c;
    }
    int t = 0;
    while(++t){
        if(!move()){
            break;
        }
        if(timeline[t]){
            rotate(timeline[t]);
        }
    }
    cout << t << '\n';
}