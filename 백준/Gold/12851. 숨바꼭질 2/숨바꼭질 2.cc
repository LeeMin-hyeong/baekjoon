#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, k;
int visited[200001];
int cnt[200001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0; i<=200000; i++){
        visited[i] = 1e9;
    }
    queue<int> q;
    q.push(n);
    visited[n] = 0;
    cnt[n] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur-1 >= 0){
            if(visited[cur-1] > visited[cur]+1){
                visited[cur-1] = visited[cur]+1;
                cnt[cur-1] = cnt[cur];
                q.push(cur-1);
            }
            else if(visited[cur-1] == visited[cur]+1){
                cnt[cur-1] += cnt[cur];
            }
        }
        if(cur+1 <= 200000){
            if(visited[cur+1] > visited[cur]+1){
                visited[cur+1] = visited[cur]+1;
                cnt[cur+1] = cnt[cur];
                q.push(cur+1);
            }
            else if(visited[cur+1] == visited[cur]+1){
                cnt[cur+1] += cnt[cur];
            }
        }
        if(cur > 0 && 2*cur <= 200000){
            if(visited[2*cur] > visited[cur]+1){
                visited[2*cur] = visited[cur]+1;
                cnt[2*cur] = cnt[cur];
                q.push(2*cur);
            }
            else if(visited[2*cur] == visited[cur]+1){
                cnt[2*cur] += cnt[cur];
            }
        }
    }
    cout << visited[k] << '\n' << cnt[k] << '\n';
}