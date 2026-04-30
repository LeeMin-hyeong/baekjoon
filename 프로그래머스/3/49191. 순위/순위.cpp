#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool edge[101][101];

int solution(int n, vector<vector<int>> results) {
    for(auto r : results){
        edge[r[0]][r[1]] = true;
    }
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(edge[i][k] && edge[k][j]){
                    edge[i][j] = true;
                }
            }
        }
    }
    
    int answer = 0;
    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(i == j) continue;
            if(edge[i][j] || edge[j][i]) cnt++;
        }
        if(cnt == n-1) answer++;
    }
    
    return answer;
}