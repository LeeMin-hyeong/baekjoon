#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s/n < 1) return {-1};
    answer.assign(n, s/n);
    int cnt = s%n;
    int idx = answer.size()-1;
    while(cnt--){
        answer[idx--]++;
    }
    return answer;
}