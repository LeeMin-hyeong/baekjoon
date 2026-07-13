#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left = 0, right = distance;
    sort(rocks.begin(), rocks.end());
    while(left <= right){
        int mid = (left+right)/2;
        int prev = 0, cnt = 0;
        for(int i=0; i<rocks.size(); i++){
            if(rocks[i]-prev < mid){
                cnt++;
            }
            else{
                prev = rocks[i];           
            }
        }
        if(distance-prev < mid) cnt++;

        if(cnt <= n){
            left = mid+1;
            answer = mid;
        }
        else{
            right = mid-1;
        }
    }
    return answer;
}