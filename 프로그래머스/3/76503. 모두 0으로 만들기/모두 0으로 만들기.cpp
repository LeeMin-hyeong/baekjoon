#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool visited[300000];
long long answer = 0;

long long postorder(int n, vector<int> &a, vector<vector<int>> &edge){
    visited[n] = true;
    long long ret = a[n];
    for(auto next : edge[n]){
        if(visited[next]) continue;
        long long child = postorder(next, a, edge);
        ret += child;
        answer += abs(child);
    }
    return ret;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long sum = 0;
    vector<vector<int>> edge(a.size());
    for(auto x : a){
        sum += x;
    }
    if(sum != 0) return -1;
    
    for(auto e : edges){
        edge[e[0]].push_back(e[1]);
        edge[e[1]].push_back(e[0]);
    }
    
    postorder(0, a, edge);
    
    return answer;
}