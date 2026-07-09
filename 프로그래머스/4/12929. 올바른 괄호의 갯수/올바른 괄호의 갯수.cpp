#include <vector>
using namespace std;

int dfs(int n, int open, int close){
    if(close == n && open == n) return 1;
    if(open == n) return dfs(n, open, close+1);
    if(open == close) return dfs(n, open+1, close);
    if(open < n && open > close) return dfs(n, open+1, close) + dfs(n, open, close+1);
}

int solution(int n) {
    int answer = dfs(n, 1, 0);
    return answer;
}