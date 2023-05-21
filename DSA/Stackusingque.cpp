#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class stackk{
    int n;
    queue<int> q1;
    queue<int> q2;
    public:
    stackk(){
        n=0;
    }
    void push(int val){
        q2.push(val);
        n++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop(){
        q1.pop();
        n--;
    }
    int top(){
        return q1.front();
    }
    int size(){
        return n;
    }
};
int main(){
    stackk st;
    st.push(10);
    st.push(12);
    st.push(14);
    st.push(16);
    st.push(18);
    cout<<st.top()<<"\n";
    st.pop();
    cout<<st.top()<<"\n";
    cout<<st.size();
}
