#include <iostream>
#include <math.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int testCase, x1, y1, x2, y2, r1, r2;
    cin>>testCase;
    int result[testCase];
    for(int i=0; i<testCase; i++){
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        double dist=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
        if(dist==0){
            if(r1==r2)
                result[i]=-1;
            else
                result[i]=0;
        }
        else if(dist<r1){
            if(r1==dist+r2)
                result[i]=1;
            else if(r1<dist+r2)
                result[i]=2;
            else
                result[i]=0;
        }
        else if(dist<r2){
            if(r2==dist+r1)
                result[i]=1;
            else if(r2<dist+r1)
                result[i]=2;
            else
                result[i]=0;
        }
        else{
            if(dist<r1+r2)
                result[i]=2;
            else if(dist==r1+r2)
                result[i]=1;
            else
                result[i]=0;
        }
    }
    for(int i=0; i<testCase; i++)
        cout<<result[i]<<"\n";
}