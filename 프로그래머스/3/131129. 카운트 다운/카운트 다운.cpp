#include <string>
#include <vector>

using namespace std;

int dart[] = {
    1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, // single
    22, 24, 26, 28, 30, 32, 34, 36, 38, 40, // double
    21, 27, 33, 39, 42, 45, 48, 51, 54, 57, 60, // triple
    50 // bool
};

vector<int> solution(int target) {
    vector<pair<int, int>> dp(max(60, target)+1, {100000, 0});
    for(int i=1; i<=20; i++){
        dp[i] = {1, 1};
        dp[2*i] = {1, 0};
        dp[3*i] = {1, 0};
    }
    dp[50] = {1, 1};

    for(int i=0; i<=target; i++){
        for(auto d : dart){
            if(i+d > target) continue;
            auto [dart, sum] = dp[i+d];
            auto [cur_d, cur_s] = dp[i];
            auto [new_d, new_s] = dp[d];
            if(cur_d+new_d < dart){
                dp[i+d] = {cur_d+new_d, cur_s+new_s};
            }
            else if(cur_d+new_d == dart && cur_s+new_s > sum){
                dp[i+d].second = cur_s+new_s;
            }
        }
    }

    return {dp[target].first, dp[target].second};
}
