#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int left = 1;
    int right = 1;
    int sum = 1;

    while(left <= n) {
        if(sum == n) {
            answer++;
            sum -= left++;
        }
        else if(sum < n) {
            right++;
            sum += right;
        }
        else {
            sum -= left++;
        }
    }

    return answer;
}