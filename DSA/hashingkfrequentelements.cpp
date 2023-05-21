//given an array and break when (k+1)th distinct element is found and output them with frequency
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int> freq;
    for(int i=0;i<n;i++){
        int currsize = freq.size();
        if(freq[a[i]] == 0 && currsize == k){
            break;
        }
        freq[a[i]]++;
    }
    vector<pair<int,int>> ans;
    map<int,int> :: iterator it;
    for(it=freq.begin();it!=freq.end();it++){
        if(it->second !=0){
            ans.push_back({it->second,it->first});
        }
    }
    sort(ans.begin(),ans.end(),greater<pair<int,int>>());// sorts the key not value
    vector<pair<int,int>> :: iterator it1;
    for(it1=ans.begin();it1!=ans.end();it1++){
        cout<<it1->second<<" "<<it1->first<<"\n";
    }
    
}