#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int n = cookie.size();
    
    for(int m=0; m<n-1; m++){
        
        int l = m, r = m+1;
        int son1 = cookie[l], son2 = cookie[r];
        while(l>=0 && r<n){
            if(son1 == son2){
                answer = max(answer, son1);
            }
            if(son1 < son2){
                if(--l>=0) son1 += cookie[l];
            }
            else{
                if(++r<n) son2 += cookie[r];
            }
        }
    }
    return answer;
}