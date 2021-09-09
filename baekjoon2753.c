#include <stdio.h>

int main(){
    int input;
    scanf("%d", &input);
    if(!(input%4)&&(input%100)||!(input%400))
        printf("1");
    else
        printf("0");
}