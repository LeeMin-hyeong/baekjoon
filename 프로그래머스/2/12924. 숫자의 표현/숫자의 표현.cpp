#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    long long sum[10001];
    int answer = 0;
    for(int i=1; i<=n; i++){
        sum[i] = i+sum[i-1];
    }
    int left = 0, right = 1;
    while(left < n){
        long long s = sum[right]-sum[left];
        if(s == n){
            answer++;
            left++;
        }
        else if(s < n) right = min(right+1, n);
        else left++;
    }
    return answer;
}