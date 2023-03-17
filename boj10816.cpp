#include <iostream>
#include <map>
using namespace std;

typedef map<int, int> ii;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m, tmp;
    cin >> n;
    ii arr;
    for(int i=0; i<n; i++){
        cin >> tmp;
        arr[tmp]++;
    }

    cin >> m;
    for(int i=0; i<m; i++){
        cin >> tmp;
        cout << arr[tmp] << " ";
    }
}

