#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int> ms;
    for(string s : operations){
        char op = s[0];
        int num = stoi(s.substr(2, s.size()-2));
        if(op == 'I'){
            ms.insert(num);
        }
        else{
            if(ms.empty()) continue;
            if(num == 1){
                ms.erase(prev(ms.end()));
            }
            if(num == -1){
                ms.erase(ms.begin());
            }
        }
    }
    if(ms.empty()){
        return {0, 0};
    }
    return {*prev(ms.end()), *ms.begin()};
}