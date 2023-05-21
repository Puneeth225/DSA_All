// given an array of size n and k find smallest subsequence length whose sum = k
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,sum =0,cnt=0;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    priority_queue<int, vector<int>>pq;
    for(int i=0;i<n;i++){
        pq.push(a[i]);
    }
    while(!pq.empty()){
        sum+=pq.top();
        pq.pop();
        cnt++;
        if(sum>=k){
            break;;
        }
    }
    if(sum<k){
        cout<<"No Subsequenc with sum = K exists"<<"\n";
    }
    else{
        cout<<cnt<<"\n";
    }

}
