#include<bits/stdc++.h>
using namespace std;
// hashing is done using maps and unordered maps
//program to count the frequency of elements
int main(){
    unordered_map<int,int> mp;
    // for(int i=1;i<=10;i++){
    //     mp[i] = i*2;
    // }
    // for(int i=1;i<=10;i++){
    //     cout<<mp[i]<<" ";
    // }
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        mp[a[i]]++;
    }
    unordered_map<int,int> :: iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<" "<<it->second<<"\n";
    }
}