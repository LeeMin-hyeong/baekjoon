#include <stdio.h>

int main(){
    int n, l, s, count=0, a[1000000];

    scanf("%d", &n);

    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    l=a[0];

    while(1){
        for(int i=0; i<n; i++){
            if(l<a[i]){
                l=a[i];
                count++;
            }
        }
        if(!count)
            break;
    }

    count=0;
    s=a[0];
    while(1){
        for(int i=0; i<n; i++){
            if(s>a[i]){
                s=a[i];
                count++;
            }
        }
        if(!count)
            break;
    }
    

    printf("%d %d", s, l);
}