// given an array in which the times to compute the files are given find minimum time to compute all files
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    priority_queue<int, vector<int>, greater<int> > minheap;
    for(int i=0;i<n;i++){
        minheap.push(a[i]);
    }
    int ans = 0;
    while(minheap.size()>1){
        int mn1 = minheap.top();
        minheap.pop();
        int mn2 = minheap.top();
        minheap.pop();
        ans += (mn1+mn2);
        minheap.push(mn1+mn2);
    }
    cout<<ans<<"\n";
}