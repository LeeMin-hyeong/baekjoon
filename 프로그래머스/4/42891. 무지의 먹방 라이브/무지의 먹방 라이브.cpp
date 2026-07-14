#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int solution(vector<int> food_times, long long k) {
    int food_cnt = food_times.size();

    for(int i=0; i<food_cnt; i++){
        pq.push({food_times[i], i+1});
    }

    int prev = 0;
    while(!pq.empty()){
        int cycle_min = pq.top().first-prev;
        int index = pq.top().second;
        long long cycle_time = pq.size() * cycle_min;

        if(k < cycle_time){
            vector<int> v;
            while(!pq.empty()){
                v.push_back(pq.top().second);
                pq.pop();
            }
            sort(v.begin(), v.end());
            return v[k%v.size()];
        }

        prev = pq.top().first;
        k -= cycle_time;
        pq.pop();
    }

    return -1;
}