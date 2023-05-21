#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reversentnce(string s){
    stack<string> st1;
    for(int i=0;i<s.length();i++){
        string ans = "";
        while(s[i]!=' ' && i<s.length()){
            ans = ans+s[i];
            i++;
        }
        st1.push(ans);
    }
    while(!st1.empty()){
        cout<<st1.top()<<" ";
        st1.pop();
    }
    cout<<"\n";
}
int main(){
    string s = "Hello Puneeth, How are you?";
    reversentnce(s);
}
