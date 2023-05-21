#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool isvalid(string s){
    int n = s.size();
    stack<char> st;
    bool ans = true;
    for(int i = 0;i<n;i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(!st.empty()&&st.top()=='('){
                st.pop();
            }
            else{
                ans = false;
            }
        }
        else if(s[i]==']'){
            if(!st.empty()&&st.top()=='['){
                st.pop();
            }
            else{
                ans = false;
            }
        }
        else if(s[i]=='}'){
            if(!st.empty()&&st.top()=='{'){
                st.pop();
            }
            else{
                ans = false;
            }
        }
    }
    if(!st.empty()){
        return false;
    }
    return ans;
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    if(isvalid(s)){
        cout<<"Valid string"<<"\n";
    }
    else{
        cout<<"Invalid"<<"\n";
    }
}



/*stack<char> st;
    string ans = "YES";
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(!st.empty()&&st.top()=='('){
                st.pop();
            }
            else{
                ans = "NO";
            }
        }
        else if(s[i]=='}'){
            if(!st.empty()&&st.top()=='{'){
                st.pop();
            }
            else{
                ans = "NO";
            }
        }
        else if(s[i]==']'){
            if(!st.empty()&&st.top()=='['){
                st.pop();
            }
            else{
                ans = "NO";
            }
        }
        
    }
    return ans;*/