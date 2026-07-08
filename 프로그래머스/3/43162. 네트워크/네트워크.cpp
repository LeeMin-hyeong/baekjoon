#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool visited[200];

void dfs(int n, int c, vector<vector<int>> computers){
    for(int i=0; i<n; i++){
        if(!computers[c][i]) continue;
        if(visited[i]) continue;
        visited[i] = true;
        dfs(n, i, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        visited[i] = true;
        dfs(n, i, computers);
        answer++;
    }
    return answer;
}