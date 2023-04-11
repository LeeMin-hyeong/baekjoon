#include <iostream>
using namespace std;
int arr[5001];
int groupscore(int start, int end){
    return *max_element(arr+start, arr+end+1)-*min_element(arr+start, arr+end+1);
}
int main(){
    int N, M; cin >> N >> M;
    for(int i=1; i<=N; i++)
        cin >> arr[i];

    int ans = 987654321;
    int high = groupscore(1, N);
    int low = 0;
    while(high >= low){
        int mid = (high+low)/2;
        int start = 1;
        int cnt = 1;
        for(int i=1; i<=N; i++){
            int temp = groupscore(start, i);
            if(temp > mid){
                start = i;
                cnt++;
            }
        }
        if(cnt <= M){
            ans = min(ans, mid);
            high = mid-1;
        }
        else low = mid+1;
    }
    cout << ans << '\n';
    // dp풀이 - 시간 초과 5000^3
    // for(int i=1; i<=N; i++)
    //     dp[i][1] = groupscore(1, i);

    // for(int j=2; j<=M; j++){
    //     for(int i=1; i<=N; i++){
    //         dp[i][j] = 987654321;
    //         for(int k=j; k<=i; k++){
    //             dp[i][j] = min(dp[i][j], max(dp[k-1][j-1], groupscore(k, i)));
    //         }
    //     }
    // }
    // cout << dp[N][M] << '\n';
}