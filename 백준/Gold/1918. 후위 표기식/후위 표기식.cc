#include <bits/stdc++.h>
using namespace std;

stack<char> op;
int main(){
    string s;
    cin >> s;
    for(int i=0; i<s.length(); i++){
        if(s[i] == '('){
            op.push(s[i]);
        }
        else if(s[i] == ')'){
            while(!op.empty() && op.top() != '('){
                cout << op.top();
                op.pop();
            }
            op.pop();
        }
        else if (s[i] == '*' || s[i] == '/'){
            while (!op.empty() && (op.top() == '*' || op.top() == '/')){
                cout << op.top();
                op.pop();
            }
            op.push(s[i]);
        }
        else if (s[i] == '+' || s[i] == '-'){
            while (!op.empty() && op.top() != '('){
                cout << op.top();
                op.pop();
            }
            op.push(s[i]);
        }
        else if (s[i] == ')'){
            while (!op.empty() && op.top() != '('){
                cout << op.top();
                op.pop();
            }
            op.pop();
        }
        else cout << s[i];
    }
    while(!op.empty()){
        cout << op.top();
        op.pop();
    }
    cout << '\n';
}