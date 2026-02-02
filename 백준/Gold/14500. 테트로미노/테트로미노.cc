#include <bits/stdc++.h>
using namespace std;

int N, M;
int paper[500][500];
int ans = 0;

void check_L_and_T(int y, int x){
    int vertical, horizonal;
    if(y+2 < N){
        vertical = paper[y][x] + paper[y+1][x] + paper[y+2][x];
        if(x-1 >= 0){
            if(ans < vertical + paper[y][x-1]){
                //cout << y << ' ' << x << " L 1\n";
                ans = vertical + paper[y][x-1];
            }
            if(ans < vertical + paper[y+1][x-1]){
                //cout << y << ' ' << x << " T 1\n";
                ans = vertical + paper[y+1][x-1];
            }
            if(ans < vertical + paper[y+2][x-1]){
                //cout << y << ' ' << x << " L 2\n";
                ans = vertical + paper[y+2][x-1];
            }
        }
        if(x+1 < M){
            if(ans < vertical + paper[y][x+1]){
                //cout << y << ' ' << x << " L 3\n";
                ans = vertical + paper[y][x+1];
            }
            if(ans < vertical + paper[y+1][x+1]){
                //cout << y << ' ' << x << " T 2\n";
                ans = vertical + paper[y+1][x+1];
            }
            if(ans < vertical + paper[y+2][x+1]){
                //cout << y << ' ' << x << " L 4\n";
                ans = vertical + paper[y+2][x+1];
            }
        }
    }
    if(x+2 < M){
        horizonal = paper[y][x] + paper[y][x+1] + paper[y][x+2];
        if(y-1 >= 0){
            if(ans < horizonal + paper[y-1][x]){
                //cout << y << ' ' << x << " L 5\n";
                ans = horizonal + paper[y-1][x];
            }
            if(ans < horizonal + paper[y-1][x+1]){
                //cout << y << ' ' << x << " T 3\n";
                ans = horizonal + paper[y-1][x+1];
            }
            if(ans < horizonal + paper[y-1][x+2]){
                //cout << y << ' ' << x << " L 6\n";
                ans = horizonal + paper[y-1][x+2];
            }
        }
        if(y+1 < N){
            if(ans < horizonal + paper[y+1][x]){
                //cout << y << ' ' << x << " L 7\n";
                ans = horizonal + paper[y+1][x];
            }
            if(ans < horizonal + paper[y+1][x+1]){
                //cout << y << ' ' << x << " T 4\n";
                ans = horizonal + paper[y+1][x+1];
            }
            if(ans < horizonal + paper[y+1][x+2]){
                //cout << y << ' ' << x << " L 8\n";
                ans = horizonal + paper[y+1][x+2];
            }
        }
    }
}

void check_box(int y, int x){
    if(y+1 < N && x+1 < M){
        int sum = paper[y][x] + paper[y+1][x] + paper[y][x+1] + paper[y+1][x+1];
        if(ans < sum){
            ans = sum;
            //cout << y << ' ' << x << " ㅁ\n";
        }
    }
}

void check_Z(int y, int x){
    if(y-1 >= 0 && x+2 < M){
        int sum = paper[y][x] + paper[y][x+1] + paper[y-1][x+1] + paper[y-1][x+2];
        if(ans < sum){
            ans = sum;
            //cout << y << ' ' << x << " Z 1\n";
        }
    }
    if(y+1 < N && x+2 < M){
        int sum = paper[y][x] + paper[y][x+1] + paper[y+1][x+1] + paper[y+1][x+2];
        if(ans < sum){
            ans = sum;
            //cout << y << ' ' << x << " Z 2\n";
        }
    }
    if(y+2 < N && x+1 < M){
        int sum = paper[y][x] + paper[y+1][x] + paper[y+1][x+1] + paper[y+2][x+1];
        if(ans < sum){
            ans = sum;
            //cout << y << ' ' << x << " Z 3\n";
        }
    }
    if(y+2 < N && x-1 >=0){
        int sum = paper[y][x] + paper[y+1][x] + paper[y+1][x-1] + paper[y+2][x-1];
        if(ans < sum){
            ans = sum;
            //cout << y << ' ' << x << " Z 4\n";
        }
    }
}

void check_I(int y, int x){
    if(x+3 < M){
        int horizonal = paper[y][x] + paper[y][x+1] + paper[y][x+2] + paper[y][x+3];
        if(ans < horizonal){
            ans = horizonal;
            //cout << y << ' ' << x << " I horizonal\n";
        }
    }
    if(y+3 < N){
        int vertical = paper[y][x] + paper[y+1][x] + paper[y+2][x] + paper[y+3][x];
        if(ans < vertical){
            ans = vertical;
            //cout << y << ' ' << x << " I vertical\n";
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> paper[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            check_box(i, j);
            check_L_and_T(i, j);
            check_Z(i, j);
            check_I(i, j);
        }
    }
    cout << ans << '\n';
}