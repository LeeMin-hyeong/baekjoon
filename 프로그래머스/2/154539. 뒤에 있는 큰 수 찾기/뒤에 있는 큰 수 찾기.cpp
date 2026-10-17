#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1);
    vector<pair<int, int>> temp;
    temp.push_back({numbers[0], 0});
    for(int i=1; i<numbers.size(); i++){
        int cur = numbers[i];
        while(!temp.empty() && temp.back().first < cur){
            answer[temp.back().second] = cur;
            temp.pop_back();
        }
        temp.push_back({cur, i});
    }
    return answer;
}