#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& money, int start, int end) {
    int prev2 = 0;
    int prev1 = 0;

    for (int i = start; i <= end; i++) {
        int cur = max(prev1, prev2 + money[i]);
        prev2 = prev1;
        prev1 = cur;
    }

    return prev1;
}

int solution(vector<int> money) {
    int n = money.size();

    int case1 = rob(money, 0, n - 2);
    int case2 = rob(money, 1, n - 1);

    return max(case1, case2);
}