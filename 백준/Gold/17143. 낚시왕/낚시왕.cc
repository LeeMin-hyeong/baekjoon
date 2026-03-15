#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstring>
#include <queue>
#include <unordered_map>
using namespace std;

int R, C, M;

class Shark{
    public:
    int r, c, s, d, z;
    Shark(int r, int c, int s, int d, int z){
        this->r = r;
        this->c = c;
        this->s = s;
        this->d = d;
        this->z = z;
    }
    
    void move(){
        if(this->d == 1 || this->d == 2){
            if(R == 1) return;

            int cycle = 2 * (R - 1);
            int move = this->s % cycle;

            int pos;
            if(this->d == 2) pos = this->r - 1;
            else pos = cycle - (this->r - 1);

            pos = (pos + move) % cycle;

            if(pos <= R - 1){
                this->r = pos + 1;
                this->d = 2;
            }
            else{
                this->r = cycle - pos + 1;
                this->d = 1;
            }
        }
        else{
            if(C == 1) return;

            int cycle = 2 * (C - 1);
            int move = this->s % cycle;

            int pos;
            if(this->d == 3) pos = this->c - 1;
            else pos = cycle - (this->c - 1);

            pos = (pos + move) % cycle;

            if(pos <= C - 1){
                this->c = pos + 1;
                this->d = 3;
            }
            else{
                this->c = cycle - pos + 1;
                this->d = 4;
            }
        }
    }
};


bool compare_by_location(Shark a, Shark b){
    if(a.c != b.c) return a.c < b.c;
    return a.r < b.r;
}

bool compare_by_size(Shark a, Shark b){
    return a.z > b.z;
}

vector<Shark> v;

void update(){
    vector<Shark> temp;
    bool occupy[101][101];
    memset(occupy, false, sizeof(occupy));
    sort(v.begin(), v.end(), compare_by_size);
    for(int i=0; i<v.size(); i++){
        Shark a = v[i];
        if(!occupy[a.r][a.c]){
            occupy[a.r][a.c] = true;
            temp.push_back(a);
        }
    }
    v = temp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> R >> C >> M;
    for(int i=0; i<M; i++){
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        v.push_back(Shark(a, b, c, d, e));
    }

    int ans = 0;
    for(int sec=1; sec<=C; sec++){
        sort(v.begin(), v.end(), compare_by_location);
        for(int i=0; i<v.size(); i++){
            if(v[i].c == sec){
                ans += v[i].z;
                v.erase(v.begin()+i);
                break;
            }
        }
        for(int i=0; i<v.size(); i++){
            v[i].move();
        }
        update();
    }
    cout << ans << '\n';
}