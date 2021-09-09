#include <stdio.h>

int x[1000];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &x[i]);
        for(int j=0; j<i; j++){
            if(x[i]==x[j]){
                i--;
                break;
            }
        }
    }
    while(1){
        int tmp, count=0;
        for(int i=0; i<n-1; i++){
            if(x[i]>x[i+1]){
                tmp=x[i];
                x[i]=x[i+1];
                x[i+1]=tmp;
                count++;
            }
        }
        if(count==0)
            break;
    }
    for(int i=0; i<n; i++)
        printf("%d\n", x[i]);
}