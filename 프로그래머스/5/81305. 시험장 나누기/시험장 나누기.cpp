#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[10000];
int cnt;

int root(vector<vector<int>>& links) {
    int n = links.size();

    for(int i = 0; i < n; i++){
        parent[i] = -1;
    }

    for(int i = 0; i < n; i++){
        for(int next : links[i]){
            if(next != -1) parent[next] = i;
        }
    }

    for(int i = 0; i < n; i++){
        if (parent[i] == -1) return i;
    }

    return -1;
}

int dfs(int t, int cur, vector<int>& num, vector<vector<int>>& links){
    if(cur == -1) return 0;

    int left = dfs(t, links[cur][0], num, links);
    int right = dfs(t, links[cur][1], num, links);

    if(num[cur] + left + right <= t){
        return num[cur] + left + right;
    }

    if(num[cur] + min(left, right) <= t){
        cnt++;
        return num[cur] + min(left, right);
    }

    if(left > 0) cnt++;
    if(right > 0) cnt++;

    return num[cur];
}

int solution(int k, vector<int> num, vector<vector<int>> links){
    int left = 0, right = 0;
    int answer = 0;

    int r = root(links);

    for(int n : num){
        left = max(left, n);
        right += n;
    }

    while(left <= right){
        cnt = 1;
        int mid = (left+right)/2;

        dfs(mid, r, num, links);

        if(cnt <= k){
            answer = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }

    return answer;
}