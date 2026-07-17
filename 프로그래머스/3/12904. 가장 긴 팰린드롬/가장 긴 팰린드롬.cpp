#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool dp[2500][2500];

int solution(string s){
    int answer = 1;
    int n = s.size();
    for(int i=0; i<n; i++){
        dp[i][i] = true;
    }
    for(int i=0; i<n-1; i++){
        if(s[i] == s[i+1]){
            dp[i][i+1] = true;
            answer = 2;
        }
    }
    for(int i=2; i<n; i++){
        for(int j=0; i+j<n; j++){
            if(s[j] == s[j+i] && dp[j+1][j+i-1]){
                dp[j][j+i] = true;
                answer = i+1;
            }
        }
    }

    return answer;
}