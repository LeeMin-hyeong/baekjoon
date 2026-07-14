#include <iostream>
#include <vector>
using namespace std;

int dp[100000][2];

int solution(vector<int> sticker){
    int n = sticker.size();
    if(n == 1) return sticker[0];
    int answer = 0;
    dp[0][1] = sticker[0];
    dp[1][0] = sticker[0];
    for(int i=1; i<n-1; i++){
        dp[i][1] = max(dp[i-1][0]+sticker[i], dp[i-1][0]);
        dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
    }
    for(int i=0; i<n-1; i++){
        answer = max(answer, max(dp[i][0], dp[i][1]));
    }
    answer = max(dp[n-2][0], dp[n-2][1]);
    
    for(int i=0; i<n; i++){
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
    
    for(int i=1; i<n; i++){
        dp[i][1] = max(dp[i-1][0]+sticker[i], dp[i-1][0]);
        dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
    }
    for(int i=1; i<n; i++){
        answer = max(answer, max(dp[i][0], dp[i][1]));
    }
    
    return answer;
}