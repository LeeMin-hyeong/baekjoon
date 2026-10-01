#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

bool visited[100];

int bfs(int cur, vector<int> cards){
    int ret = 0;
    while(!visited[cur]){
        visited[cur] = true;
        cur = cards[cur]-1;
        ret++;
    }
    return ret;
}

int solution(vector<int> cards) {
    int answer = 0;
    vector<int> cand;
    for(int i=0; i<cards.size(); i++){
        int ret = bfs(i, cards);
        if(ret != 0) cand.push_back(ret);
    }
    if(cand.size() == 1) return 0;

    sort(cand.rbegin(), cand.rend());

    return cand[0]*cand[1];
}