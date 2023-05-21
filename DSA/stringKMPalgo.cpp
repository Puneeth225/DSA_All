//find indices of occurrunces of string s in string t
//O(s.size()+t.size())
#include<bits/stdc++.h>
using namespace std;
vector<int> prefixfunc(string s){
    int n = s.size();
    vector<int>pfunc(n,0);
    for(int i=1;i<n;i++){
        int j = pfunc[i-1];
        while(j>0 && s[i]!=s[j]){
            j = pfunc[j-1];
        }
        if(s[i] == s[j]){
            j++;
        }
        pfunc[i] = j;
    }
    return pfunc;
}
int main(){
    string s = "nee";
    vector<int> res = prefixfunc(s);
    // for(auto i:res){
    //     cout<<i<<" ";
    // }
    string t = "puneeth";
    int pos = -1;
    int i(0),j(0); //similar to i=0,j=0
    while(i<t.size()){
        if(t[i] == s[j]){
            j++;
            i++;
        }
        else{
            if(j!=0){
                j = res[j-1];
            }
            else{
                i++;
            }
        }
        if(j==s.size()){
            pos = i-s.size();
            break;
        }
    }
    cout<<pos;
    cout<<"\n";
}