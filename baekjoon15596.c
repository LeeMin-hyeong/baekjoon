#include <stdio.h>

long long sum();

int main(){
    int a[5]={1, 2, 3, 4, 5};
    printf("%lld\n", sum(a, 5));
}

long long sum(int *a, int n){
    long long b=0;
    for(int i=0; i<n; i++)
        b+=a[i];
    return b;
}