#include <string>
#include <vector>
#define MOD 1234567

using namespace std;

long long solution(int n) {
    long long dp1 = 1, dp2 = 1, answer = 1;
    for(int i=1; i<n; i++){
        answer = (dp1+dp2)%MOD;
        dp1 = dp2;
        dp2 = answer;
    }
    return answer;
}