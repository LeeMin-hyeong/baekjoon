#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string s;
int k, m;
unordered_map<long long, int> um;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s >> k >> m;

    for (int i = 0; i + k <= s.size(); i++) {
        long long cur = 0;
        for (int j = 0; j < k; j++) {
            cur = cur * 2 + (s[i + j] - '0');
        }

        um[cur]++;

        if (um[cur] >= m) {
            cout << 1 << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';
    return 0;
}