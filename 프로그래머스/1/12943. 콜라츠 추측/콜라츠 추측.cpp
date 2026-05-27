#include <string>
#include <vector>

using namespace std;

int collatz(long long n, int cnt){
    if(n == 1) return cnt;
    if(cnt >= 500 && n != 1) return -1;
    return (n%2 == 0 ? collatz(n/2, cnt+1) : collatz(3*n+1, cnt+1));
}

int solution(int num) {
    return collatz(num, 0);
}