#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    vector<int> prev(n, 0);
    vector<int> next(n, 0);
    vector<bool> deleted(n, 0);
    stack<int> del;
    int cur = k;
    int last = n-1;
    for(int i=0; i<n; i++){
        prev[i] = i-1;
        next[i] = i+1;
    }
    next[n-1] = -1;
    
    for(auto &s : cmd){
        if(s[0] == 'U'){
            int move = stoi(s.substr(2));
            while(move--) cur = prev[cur];
        }
        else if(s[0] == 'D'){
            int move = stoi(s.substr(2));
            while(move--) cur = next[cur];
        }
        else if(s[0] == 'C'){
            del.push(cur);
            deleted[cur] = true;

            int p = prev[cur];
            int nx = next[cur];

            if (p != -1) next[p] = nx;
            if (nx != -1) prev[nx] = p;

            cur = (nx != -1) ? nx : p;
        }
        else if(s[0] == 'Z'){
            int undo = del.top();
            del.pop();
            deleted[undo] = false;

            int p = prev[undo];
            int nx = next[undo];

            if (p != -1) next[p] = undo;
            if (nx != -1) prev[nx] = undo;
        }
    }
    
    string answer = "";
    for(int i=0; i<n; i++){
        answer += deleted[i] ? "X" :"O";
    }
    return answer;
}
