// given an array divide it into two arrays of size (n/2) and find the minimum and maximum difference between the two array elements
#include <bits/stdc++.h>
using namespace std;
#define ll long long
//first sort the array
//for maximum difference subtract first (n/2) elements from last (n/2) elements
// for minimum difference subtract even indexed elements from odd indexed 
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i: a){
        cin>>i;
    }
    sort(a.begin(),a.end());
    ll mn = 0,mx = 0;
    for(int i=0;i<(n/2);i++){
        mx += (a[i+(n/2)] - a[i]);
        mn += (a[2*i+1] - a[2*i]);
    }
    cout<<mx<<" "<<mn<<"\n";

}