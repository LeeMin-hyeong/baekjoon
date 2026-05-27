#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string s) {
    vector<int> v;
    int i=0;
    while(i < s.size()){
        int st = i;
        int cnt = 0;
        while(s[i++] != ' '){
            cnt++;
        }
        v.push_back(stoi(s.substr(st, cnt)));
    }
    return to_string(*min_element(v.begin(), v.end())) + " " + to_string(*max_element(v.begin(), v.end()));
}