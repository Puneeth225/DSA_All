// given an array find the minimum sum of K consecutive elements
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,sum=0,ans=INT_MAX;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<k;i++){
        sum+=a[i];
    }
    ans = min(ans,sum);
    for(int i=1;i<n-k+1;i++){
        sum -= a[i-1];
        sum += a[i+k-1];
        ans = min(ans,sum);
    }
    cout<<ans<<"\n";
}
