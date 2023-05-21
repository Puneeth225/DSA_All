//find maximum length of bitonic subsequence
//bitonic is either increasing or decreasing or is first strictly increasing then strictly decreasing
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=8,ans=0;
    vector<int> a = {1,11,2,10,4,5,2,1};
    vector<int> increase(n,1), decrease(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                increase[i] = max(increase[i],1+increase[j]);
            }
        }
    }
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(a[i]>a[j]){
                decrease[i] = max(decrease[i],1+decrease[j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        ans = max(ans,increase[i]+decrease[i]-1);
    }
    cout<<ans<<"\n";
}