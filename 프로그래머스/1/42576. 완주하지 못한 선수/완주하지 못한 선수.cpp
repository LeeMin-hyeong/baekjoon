#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {
    for(auto p : participant){
        m[p]++;
    }
    for(auto c : completion){
        m[c]--;
    }
    unordered_map<string,int>::iterator i;
    for(i = m.begin(); i!=m.end(); i++){
        if(i->second == 1) return i->first;
    }
}