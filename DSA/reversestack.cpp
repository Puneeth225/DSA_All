#include<bits/stdc++.h>
using namespace std;

void insertatbotom(stack<int> &st1, int ele){
    if(st1.empty()){
        st1.push(ele);
        return;
    }
    int upele = st1.top();
    st1.pop();
    insertatbotom(st1,ele);
    st1.push(upele);
}
void reverse(stack<int> &st1){
    if(st1.empty()){
        return;
    }
    int upper = st1.top();
    st1.pop();
    reverse(st1);
    insertatbotom(st1,upper);
}
int main(){
    stack<int> st;
    st.push(44);
    st.push(45);
    st.push(46);
    st.push(47);
    st.push(48);
    reverse(st);   //original stack is 48 47 46 45 44
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n";
}
