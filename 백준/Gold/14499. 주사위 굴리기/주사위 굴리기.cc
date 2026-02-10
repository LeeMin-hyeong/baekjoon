#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, k;
int world[20][20];

int dice[4][3];

int dice_top(){
    return dice[1][1];
}

void north(){
    int temp = dice[0][1];
    dice[0][1] = dice[1][1];
    dice[1][1] = dice[2][1];
    dice[2][1] = dice[3][1];
    dice[3][1] = temp;
}

void south(){
    int temp = dice[2][1];
    dice[2][1] = dice[1][1];
    dice[1][1] = dice[0][1];
    dice[0][1] = dice[3][1];
    dice[3][1] = temp;
}

void east(){
    int temp = dice[1][2];
    dice[1][2] = dice[1][1];
    dice[1][1] = dice[1][0];
    dice[1][0] = dice[3][1];
    dice[3][1] = temp;
}

void west(){
    int temp = dice[1][0];
    dice[1][0] = dice[1][1];
    dice[1][1] = dice[1][2];
    dice[1][2] = dice[3][1];
    dice[3][1] = temp;
}

void copy_dice(){
    if (world[y][x] == 0) {
        world[y][x] = dice[3][1];
    } else {
        dice[3][1] = world[y][x];
        world[y][x] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> y >> x >> k;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> world[i][j];
        }
    }

    for(int i=0; i<k; i++){
        int a; cin >> a;
        switch(a){
            case 1: // east
                if(x+1 >= m) break;
                x++;
                east();
                copy_dice();
                cout << dice_top() << '\n';
                break;
            case 2: // west
                if(x-1 < 0) break;
                x--;
                west();
                copy_dice();
                cout << dice_top() << '\n';
                break;
            case 3: // north
                if(y-1 < 0) break;
                y--;
                north();
                copy_dice();
                cout << dice_top() << '\n';
                break;
            case 4: // south
                if(y+1 >= n) break;
                y++;
                south();
                copy_dice();
                cout << dice_top() << '\n';
                break;
        }
    }
}
