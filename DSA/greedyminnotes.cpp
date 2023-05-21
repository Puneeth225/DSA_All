// you are given the denominations in an array and find mininmum no. of notes/coins required to make value x
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    sort(a.begin(),a.end(),greater<int>());
    int noofnotes =0;
    for(int i=0;i<n;i++){
        noofnotes += x/a[i];
        x -= (x/a[i])*a[i];
    }
    cout<<noofnotes<<"\n";
}