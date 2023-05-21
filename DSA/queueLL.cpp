#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};
class Queue{
    node *front;
    node *back;
    public:
    Queue(){
        front = NULL;
        back = NULL;
    }
    void push(int x){
        node* n = new node(x);
        if(front==NULL){
            back = n;
            front = n;
            return;
        }
        back->next = n;
        back = n;
    }
    void pop(){
        if(front==NULL){
            cout<<"Empty Queue"<<"\n";
            return;
        }
        node *bedel = front;
        front = front->next;
        delete bedel;
    }
    int peek(){
        if(front==NULL){
            cout<<"No element in Queue"<<"\n";
            return -1;
        }
        return front->data;
    }
    bool empty(){
        if(front==NULL){
            return true;
        }
        return false;
    }
};
int main(){
    Queue q1;
    q1.push(1);
    q1.push(10);
    q1.push(11);
    q1.push(15);
    q1.push(19);
    cout<<q1.peek()<<"\n";
    q1.pop();
    cout<<q1.peek()<<"\n";
    cout<<q1.empty()<<"\n";//Not empty queue
}
