#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define n 100
class queueue{
    int *arr;
    int front,back;

    public:
    queueue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }
    void push(int x){
        if(back==n-1){
            cout<<"Queue filled"<<"\n";
            return;
        }
        back++;
        arr[back] = x;
        if(front == -1){
            front++;
        }
    }
    void pop(){
        if(front==-1||front>back){
            cout<<"No element to pop"<<"\n";
            return;
        }
        front++;
    }
    int peek(){
        if(front==-1||front>back){
            cout<<"No element in queue"<<"\n";
            return -1;
        }
        return arr[front];
    }
    bool empty(){
        if(front==-1||front>back){
            return true;
        }
        return false;
    }
};
int main(){


    queueue q1;
    q1.push(1);//front
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    q1.push(6);//back
    cout<<q1.peek()<<"\n";
    q1.pop();
    cout<<q1.peek()<<"\n";
    cout<<q1.empty();
}