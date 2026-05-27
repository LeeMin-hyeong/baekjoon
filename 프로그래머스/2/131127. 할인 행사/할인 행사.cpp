#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int s = 0, e = 10;
    unordered_map<string, int> m;
    for(int i=0; i<want.size(); i++){
        m[want[i]] = number[i];
    }
    for(int i=0; i<10; i++){
        m[discount[i]]--;
    }
    bool a = true;
    for(auto p : want){
        if(m[p] != 0){
            a = false;
        }
    }
    if(a) answer++;
    while(e < discount.size()){
        m[discount[s++]]++;
        m[discount[e++]]--;
        bool a = true;
        for(auto p : want){
            if(m[p] != 0){
                a = false;
            }
        }
        if(a) answer++;
    }
    
    return answer;
}