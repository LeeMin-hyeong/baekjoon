#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define INF 987654321
using namespace std;

vector<int> dijkstra(int n, int start, vector<vector<int>> &edges){
    vector<int> dist(n+1, INF);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        auto [w, cur] = pq.top();
        pq.pop();
        if(dist[cur] < w) continue;
        for(int next=1; next<=n; next++){
            if(edges[cur][next] == INF) continue;

            int fare = edges[cur][next] + dist[cur];
            if(fare < dist[next]){
                dist[next] = fare;
                pq.push({fare, next});
            }
        }
    }
    return dist;
}


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<vector<int>> edges(n+1, vector<int>(n+1, INF));
    for(auto f : fares){
        int node_1 = f[0];
        int node_2 = f[1];
        int fare = f[2];
        edges[node_1][node_2] = fare;
        edges[node_2][node_1] = fare;
    }
    vector<int> dist_s = dijkstra(n, s, edges);
    vector<int> dist_a = dijkstra(n, a, edges);
    vector<int> dist_b = dijkstra(n, b, edges);
    
    int answer = INF;
    for(int k=1; k<=n; k++){
        answer = min((long long)answer, (long long)dist_s[k]+dist_a[k]+dist_b[k]);
    }
    return answer;
}