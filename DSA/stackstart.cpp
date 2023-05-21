#include<iostream>
using namespace std;
//#define 100 n;
class stack{
    int *arr;
    int top;
    public:
    int n = 100;
    stack(){
        
        arr = new int[n];
        top = -1;
    }
    void push(int x){
        if(top == n-1){
            cout<<"Stack full"<<"\n";
            return;
        }
        top++;
        arr[top] = x;
    }
    void pop(){
        if(top==-1){
            cout<<"Empty stack"<<"\n";
            return;
        }
        top--;
    }
    int startofstack(){
        if(top==-1){
            cout<<"No element in stack"<<"\n";
            return -1;
        }
        return arr[top];
    }
    bool empty(){
        return top == -1;
    }
};

int main(){
    stack st1;
    st1.push(22);
    st1.push(44);
    st1.push(33);
    st1.push(100);
    cout<<st1.startofstack()<<"\n";
    st1.pop();
    cout<<st1.startofstack()<<"\n";
    st1.pop();
    st1.empty();
    st1.pop();
    st1.pop();
    st1.pop();
    st1.empty();

}