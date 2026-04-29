#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int s = 0;
    sort(score.begin(), score.end());
    for(int i = score.size()%m; i<score.size(); i+=m){
        s += score[i];
    }
    return s*m;
}