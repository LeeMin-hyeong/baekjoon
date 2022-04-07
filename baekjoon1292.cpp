#include <iostream>
using namespace std;

int main(){
    int start=0, end=0, i=0, j=0, sum=0, tmp;
    cin>>start;
    cin>>end;
    tmp=start;
    while(tmp>0){
        i++;
        tmp-=i;
    }
    tmp=end;
    while(tmp>0){
        j++;
        tmp-=j;
    }
    if(start==end){
        cout<<i<<endl;
        return 0;
    }
    else if(end>i*(i+1)/2){
        sum+=i*(i*(i+1)/2-start+1);
        i++;
        while(i<j){
            sum+=i*i;
            i++;
        }
        sum+=i*(end-(i*(i-1)/2));
    }
    else
        sum=i*(end-start+1);
    cout<<sum<<endl;
}