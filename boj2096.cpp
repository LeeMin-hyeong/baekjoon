#include <iostream>
using namespace std;

int dpmax[2][3];
int dpmin[2][3];
int arr[3];
int main(){
    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> arr[0] >> arr[1] >> arr[2];
        if(i==0){
            dpmax[0][0] = arr[0];
            dpmax[0][1] = arr[1];
            dpmax[0][2] = arr[2];
            dpmin[0][0] = arr[0];
            dpmin[0][1] = arr[1];
            dpmin[0][2] = arr[2];
        }
        else{
            dpmax[1][0] = max(dpmax[0][0], dpmax[0][1])+arr[0];
            dpmax[1][1] = max(dpmax[0][0], max(dpmax[0][1], dpmax[0][2]))+arr[1];
            dpmax[1][2] = max(dpmax[0][1], dpmax[0][2])+arr[2];

            dpmax[0][0] = dpmax[1][0];
            dpmax[0][1] = dpmax[1][1];
            dpmax[0][2] = dpmax[1][2];
            dpmax[1][0] = 0;
            dpmax[1][1] = 0;
            dpmax[1][2] = 0;
            
            dpmin[1][0] = min(dpmin[0][0], dpmin[0][1])+arr[0];
            dpmin[1][1] = min(dpmin[0][0], min(dpmin[0][1], dpmin[0][2]))+arr[1];
            dpmin[1][2] = min(dpmin[0][1], dpmin[0][2])+arr[2];
            
            dpmin[0][0] = dpmin[1][0];
            dpmin[0][1] = dpmin[1][1];
            dpmin[0][2] = dpmin[1][2];
            dpmin[1][0] = 0;
            dpmin[1][1] = 0;
            dpmin[1][2] = 0;
        }
    }
    int maxans = 0, minans = 987654321;
    for(int i=0; i<3; i++){
        maxans = max(maxans, dpmax[0][i]);
        minans = min(minans, dpmin[0][i]);
    }
    cout << maxans << ' ' << minans << '\n';
}