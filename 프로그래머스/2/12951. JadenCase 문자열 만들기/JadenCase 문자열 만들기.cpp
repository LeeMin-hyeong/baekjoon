#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = "";
    bool f = true;
    for(int i=0; i<s.size(); i++){
        if(s[i] == ' '){
            f = true;
            answer += ' ';
        }
        else{
            if(f){
                if(islower(s[i])){
                    answer += toupper(s[i]);
                }
                else{
                    answer += s[i];
                }
                f = false;
            }
            else{
                answer += tolower(s[i]);
            }
        }
    }
    
    return answer;
}