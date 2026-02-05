#include <bits/stdc++.h>
using namespace std;
bool prime[4000001];
vector<long long> p, p_sum;
int n;

int main(){
    cin >> n;
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;

    for(int i=2; i<4000000; i++){
        for(int j=2; i*j<4000000; j++){
            if(prime[i]){
                prime[i*j] = false;
            }
        }
    }
    p_sum.push_back(0);
    long long sum = 0;
    for(int i=2; i<4000000; i++){
        if(prime[i]){
            sum += i;
            p_sum.push_back(sum);
        }
    }
    int cnt = 0, l = 0, r = 0;
    while(l <= r && r < p_sum.size()){
        long long tmp = p_sum[r]-p_sum[l];
        if(tmp < n){
            r++;
        }
        else if(tmp > n){
            l++;
        }
        else{
            cnt++;
            r++;
        }
    }
    cout << cnt << '\n';
}