#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void Hanoi(int n, int from, int by, int to){
    if(n==1)
        cout<<from<<" "<<to<<"\n";
    else{
        Hanoi(n-1, from, to, by);
        Hanoi(1, from, by, to);
        Hanoi(n-1, by, from, to);
    }
}

int main(){
    cin.tie(NULL);  
    ios_base::sync_with_stdio(false);
    int input;
    string count;
    cin>>input;
    count=to_string(pow(2, input));
    int index=count.find('.');
    count=count.substr(0, index);
    count[count.length()-1]-=1;
    cout<<count<<"\n";
    if(input<=20)
        Hanoi(input, 1, 2, 3);
}
