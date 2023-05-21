//given an array of size n find maximum sum subarray with size k and sum<x
#include<bits/stdc++.h>
using namespace std;
int maxsubarraysum(int arr[],int n,int k, int x){
    int sum = 0,ans = 0;
    for(int i=0;i<k;i++){
        sum +=arr[i];
    }
    if(sum<x){
        ans = sum;
    }
    for(int i=k;i<n;i++){
        sum = sum-arr[i-k];
        sum = sum+arr[i];
        if(sum<x){
            ans = max(ans,sum);
        }
    }
    return ans;
}
int main(){
    int a[] = {7,5,4,6,8,9};
    int k = 3;
    int x = 20,n = 6;
    int res = maxsubarraysum(a,n,k,x);
    cout<<"Maximum subarray sum < "<<x<<" and size "<<k<<" is: "<<res<<"\n";
}