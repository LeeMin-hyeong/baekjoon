#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
using namespace std;

int n;
long long ans;
vector<int> skill;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int a; cin >> a;
        skill.push_back(a);
    }
    sort(skill.begin(), skill.end());
    queue<tuple<int, int, int>> q;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int sum = skill[i]+skill[j];
            int cnt = upper_bound(skill.begin()+j+1, skill.end(), -sum) - lower_bound(skill.begin()+j+1, skill.end(), -sum);
            ans += cnt;
        }
    }
    cout << ans << '\n';
}
