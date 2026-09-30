#include <string>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

vector<int> edges[101];
bool visited[101];

int bfs(int s, int dont){
    int ret = 1;
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto next : edges[cur]){
            if(visited[next]) continue;
            if(next == dont) continue;
            visited[next] = true;
            q.push(next);
            ret++;
        }
    }
    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 7654321;
    for(auto w : wires){
        int a = w[0];
        int b = w[1];
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    for(auto w : wires){
        memset(visited, false, sizeof(visited));
        int a = bfs(w[0], w[1]);
        int b = bfs(w[1], w[0]);
        answer = min(answer, abs(a-b));
    }
    return answer;
}