#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int parent[100];
typedef tuple<int, int, int> iii;
priority_queue<iii, vector<iii>, greater<iii>> pq;

int find(int n){
    if(n == parent[n]) return parent[n];
    return parent[n] = find(parent[n]);
}

bool union_find(int p, int q){
    int pp = find(p);
    int pq = find(q);
    if(pp == pq) return false;
    if(pp == pq) return false;
    if(pp < pq) parent[pq] = pp;
    else parent[pp] = pq;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for(auto c : costs){
        pq.push({c[2], c[0], c[1]});
    }
    for(int i=0; i<n; i++){
        parent[i] = i;
    }
    while(!pq.empty()){
        auto [w, p, q] = pq.top();
        pq.pop();
        if(union_find(p, q)) answer += w;
    }
    return answer;
}