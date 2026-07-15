#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> m;

vector<int> solution(vector<string> gems) {
    int n = gems.size();
    int left = 0;
    int best_left = 0, best_right = n-1;
    for(int i=0; i<n; i++){
        m[gems[i]]++;
    }
    int gem_cnt = m.size();
    m.clear();
    for(int right=0; right<n; right++){
        m[gems[right]]++;

        while(m.size() == gem_cnt){
            if (right - left < best_right - best_left) {
                best_left = left;
                best_right = right;
            }
            m[gems[left]]--;
            if(m[gems[left]] == 0) m.erase(gems[left]);

            left++;
        }
    }
    
    return {best_left+1, best_right+1};
}