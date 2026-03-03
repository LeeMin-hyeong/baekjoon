#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
unordered_map<int, int> m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        int t_in, t_out;
        cin >> t_in >> t_out;
        m[t_in] += 1;
        m[t_out] -= 1;
        v.push_back(t_in);
        v.push_back(t_out);
    }

    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int cnt = 0, max_cnt = 0;
    int s, e;
    bool flag = false;
    for(int i=0; i<v.size(); i++){
        int c = v[i];
        cnt += m[c];
        if(cnt > max_cnt){
            max_cnt = cnt;
            s = c;
            flag = true;
        }
        else if(cnt < max_cnt && flag){
            e = v[i];
            flag = false;
        }
    }
    cout << max_cnt << '\n';
    cout << s << ' ' << e << '\n';
}
