#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int dp1 = 0, dp2 = 1;
    for(int i=2; i<=n; i++){
        int np = (dp1+dp2)%1234567;
        dp1 = dp2;
        dp2 = np;
    }
    return dp2;
}