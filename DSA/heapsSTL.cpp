//we can access heaps in STL by priority queue
#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int, vector<int>> mxheap;
    mxheap.push(10);
    mxheap.push(12);
    mxheap.push(20);
    mxheap.push(8);
    cout<<mxheap.top()<<"\n";
    mxheap.pop();
    cout<<mxheap.top()<<"\n";
    priority_queue<int,vector<int>,greater<int>> minheap;
    minheap.push(4);
    minheap.push(2);
    minheap.push(10);
    minheap.push(11);
    cout<<minheap.top()<<"\n";
    minheap.pop();
    cout<<minheap.top()<<"\n";
}