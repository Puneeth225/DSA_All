#include <bits/stdc++.h>
using namespace std;
//dict(256,-1) is assigned as -1 for all ascii values b/w 0-255 and if anything repeats start increases to dict(i)
//let aba is input dict[s[0]] = dict[97] = -1 when again 'a' comes dict[97] is 0, larger than start = -1 so start changes
int main(){
    string s;
    cin>>s;
    vector<int> dict(256,-1);
    int maxlensubarr = 0,start = -1;
    for(int i=0;i<s.size();i++){
        if(dict[s[i]]>start){   //first if block runs then dict[s[i]] = i is initialized
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        maxlensubarr = max(maxlensubarr,i-start);
    }
    cout<<maxlensubarr<<"\n";
}

