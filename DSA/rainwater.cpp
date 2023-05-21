//max rain water conserved 

#include <bits/stdc++.h>
using namespace std;
int waterconserve(vector<int>a){
    stack<int> st;
    int n = a.size(),mxwtr = 0;
    for(int i=0;i<n;i++){
        while(!st.empty()&&a[st.top()]<a[i]){
            int minhgt = st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int len = i-st.top()-1;            //here st.top() returns after pop of top element
            mxwtr += (min(a[st.top()],a[i])-a[minhgt])*len;
        }
        st.push(i);
    }
    return mxwtr;
}

int main(){
    vector<int> a1 = {0,1,0,2,1,0,1,3,2,1,2,1};    
    cout<<waterconserve(a1);
}



