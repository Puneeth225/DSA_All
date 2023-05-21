// given an array count number of subarrays with sum = 0
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int> mp;
    int prevsum = 0,ans = 0;
    for(int i=0;i<n;i++){
        prevsum+=a[i];
        mp[prevsum]++;
    }
    map<int,int> :: iterator it;
    for(it = mp.begin();it!=mp.end();it++){
        //if more than one time the same prevsum occurs implies sum between them is 0. then compute (prevsum)C2
        ans += ((it->second)*(it->second-1))/2;
        if(it->first == 0){
            ans += it->second;
        }
    }
    cout<<ans<<"\n";
}