//given string s and t find indices of occurences of s in t
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s = "nee";
    string t = "Puneeth";
    int l1 = s.size();
    int l2 = t.size();
    for(int i=0;i<l2-l1+1;i++){
        if(t.substr(i,l1) == s){
            cout<<"Found at "<<i+1<<"\n";
        }
    }
}