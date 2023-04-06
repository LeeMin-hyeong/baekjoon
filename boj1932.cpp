#include <iostream>
#include <algorithm>
using namespace std;

int n, mem[500][999], triangle[500][999];

int main(){
    cin >> n;
    int index = (2*n-1)/2;
    for(int i=0; i<n; i++)
        for(int j=index-i; j<=index-i+2*i; j+=2)
            cin >> triangle[i][j];

    mem[0][index] = triangle[0][index];
    index = (2*n-1)/2;
    for(int i=1; i<n; i++){
        for(int j=index-i; j<=index-i+2*i; j+=2){
            if(j==0) mem[i][j] = mem[i-1][j+1]+triangle[i][j];
            else if(j==index-i+2*i) mem[i][j] = mem[i-1][j-1]+triangle[i][j];
            else mem[i][j] = max(mem[i-1][j-1], mem[i-1][j+1])+triangle[i][j];
        }
    }
    
    cout << *max_element(mem[n-1], mem[n-1]+2*(n-1)+1) << "\n";
}