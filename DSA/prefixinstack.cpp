#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int prefixcalc(string s){
    stack<int> st;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0'&&s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            switch (s[i])
            {
            case '+':
                st.push(a+b);
                break;
            case '-':
                st.push(a-b);
                break;
            case '*':
                st.push(a*b);
                break;
            case '/':
                st.push(a/b);
                break;
            case '^':
                st.push(pow(a,b));
                break;
            default:
                break;
            }
        }
    }
    return st.top();
}
int main(){
    cout<<prefixcalc("-+7*45+20");  
    return 0;
}