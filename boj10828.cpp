#include <iostream>
using namespace std;


class Stack
{
private:
    int *stack;
    int capacity;
    int top;
public:
    Stack(){
        stack=new int[10000];
        top=-1;
        capacity=0;
    }
    void Push(int x){
        stack[top<0?(top=0):(++top)]=x;
        capacity++;
    }
    void Pop(){
        if(capacity==0)
            cout<<-1<<"\n";
        else{
            cout<<stack[top]<<"\n";
            stack[top]=0;
            top--;
            capacity--;
        }
    }
    void Size(){
        cout<<capacity<<"\n";
    }
    void Empty(){
        cout<<(capacity==0?1:0)<<"\n";
    }
    void Top(){
        cout<<(top==-1?top:stack[top])<<"\n";
    }
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    Stack stack;
    string input;
    int n, x;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>input;
        if(input=="push"){
            cin>>x;
            stack.Push(x);
        }
        else if(input=="pop")
            stack.Pop();
        else if(input=="size")
            stack.Size();
        else if(input=="empty")
            stack.Empty();
        else if(input=="top")
            stack.Top();
    }
}