//checks if has extra brackets such as (a+b)((a-b)) has extra brackets for a-b
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cout<<"Enter string"<<"\n";
    cin>>s;
    bool ans = false;
    stack<char> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='+' || s[i]=='-' ||s[i]=='*' ||s[i]=='/'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.top()=='('){
                ans = true;
            }
            while(st.top()=='+'||st.top()=='-'||st.top()=='*'||st.top()=='/'){
                st.pop();
            }
            st.pop();
        }
    }
    cout<<ans;
}

