#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    int n = cookie.size();
    vector<int> A(n+1, 0);
    for(int i=1; i<=n; i++){
        A[i] = cookie[i-1]+A[i-1];
    }
    for(int m=1; m<n; m++){
        int l = 0, r = n;
        while(l<m && r>m){
            int son1_max = A[m]-A[0];
            int son2_max = A[n]-A[m];
            if(min(son1_max, son2_max) < answer) break;
            int son1 = A[m]-A[l];
            int son2 = A[r]-A[m];
            
            if(son1 < son2){
                r--;
            }
            else if(son1 == son2){
                answer = max(answer, son1);
                break;
            }
            else{
                l++;
            }
        }
    }
    return answer;
}