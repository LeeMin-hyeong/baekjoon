#include <iostream>
using namespace std;

int main(){
    int n, i=0, tmp;
    cin>>n;
    tmp=n;
    while(tmp>0){
        i++;
        tmp-=i;
    }
    int index=n-(1+i*(i-1)/2);
    if(i%2==1)
        cout<<i-index<<"/"<<1+index<<endl;
    else
        cout<<1+index<<"/"<<i-index<<endl;
}