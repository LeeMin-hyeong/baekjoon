#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<int> dest(n+1, 123456);
    vector<vector<int>> v(n+1);
    for(auto a : roads){
        v[a[0]].push_back(a[1]);
        v[a[1]].push_back(a[0]);
    }
    queue<pair<int, int>> q;
    q.push({destination, 0});
    dest[destination] = 0;
    while(!q.empty()){
        int c = q.front().first;
        int d = q.front().second;
        q.pop();
        for(int next : v[c]){
            if(dest[next] != 123456) continue;
            q.push({next, d+1});
            dest[next] = d+1;
        }
    }
    for(auto s : sources){
        answer.push_back(dest[s] == 123456 ? -1 : dest[s]);
    }
    return answer;
}