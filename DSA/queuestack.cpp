#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Queue{
    stack<int> st1;
    stack<int> st2;
    public:
    void push(int x){
        st1.push(x);
    }
    int pop(){
        if(st1.empty() && st2.empty()){
            cout<<"Empty Queue"<<"\n";
            return -1;
        }
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        int upval = st2.top();
        st2.pop();
        return upval;
    }
    bool empty(){
        if(st1.empty()&&st2.empty()){
            return true;
        }
        return false;
    }
};
int main(){
    Queue q1;
    q1.push(12);
    q1.push(122);
    q1.push(18);
    q1.push(14);
    q1.push(115);
    q1.push(169);
    cout<<q1.pop()<<"\n";
    q1.push(30);
    cout<<q1.pop()<<"\n";
    cout<<q1.empty()<<"\n";
}


//--------Second method using only one stack----------//


/*#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Queue{
    stack<int> st1;
    public:
    void push(int x){
        st1.push(x);
    }
    int pop(){
        if(st1.empty() ){
            cout<<"Empty Queue"<<"\n";
            return -1;
        }
        int val = st1.top();
        st1.pop();
        if(st1.empty()){
            return val;
        }
        int item = pop();
        st1.push(val);
        return item;
    }
    bool empty(){
        if(st1.empty()){
            return true;
        }
        return false;
    }
};
int main(){
    Queue q1;
    q1.push(12);
    q1.push(122);
    q1.push(18);
    q1.push(14);
    q1.push(115);
    q1.push(169);
    cout<<q1.pop()<<"\n";
    q1.push(30);
    cout<<q1.pop()<<"\n";
    cout<<q1.empty()<<"\n";
}*/
