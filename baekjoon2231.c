#include <stdio.h>
#include <math.h>

int main(){
    int i, n, k, m=0, l=0, sum=0, tmp=0;
    scanf("%d", &n);
    tmp=n;
    while(tmp){
        m++;
        tmp/=10;
    }

    for(i=9*m; i>=1; i--){
        sum=0;
        k=n-i;
        tmp=k;
        l=0;
        while(tmp){
            l++;
            tmp/=10;
        }
        for(int j=0; j<l; j++){
            int q=1;
            for(int k=0; k<j; k++){
                q*=10;
            }
            sum+=(k/q)%10;
        }
        if(sum==i)
            break;
    }

    if(sum==i){
        printf("%d\n", k);
    }else{
        printf("0\n");
    }
}