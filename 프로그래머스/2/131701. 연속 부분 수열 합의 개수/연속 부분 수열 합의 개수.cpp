#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    int n = elements.size();
    unordered_set<int> us;

    vector<int> sum(2*n+1);

    for(int i=0; i<2*n; i++)
        sum[i+1] = sum[i] + elements[i%n];

    for(int len=1; len<=n; len++) {
        for(int i=0; i<n; i++) {
            us.insert(sum[i+len] - sum[i]);
        }
    }

    return us.size();
}