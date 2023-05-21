//given an array find the minimum subarray size with sum > x
#include<bits/stdc++.h>
using namespace std;
int smallestsubarraysize(int arr[],int n,int x){
    int sum=0,leastsize = n+1;
    int start = 0,end = 0;
    while(end<n){
        while(sum<=x&&end<n){
            sum+=arr[end++];
        }
        while(sum>x && start <n){
            if(end-start<leastsize){
                leastsize = end - start;
            }
            sum = sum - arr[start++];
        }
    }
    return leastsize;
}
int main(){
    int a[] = {1,4,45,6,10,19};
    int x = 51,n = 6;
    int ans = smallestsubarraysize(a,n,x);
    if(ans == n+1){
        cout<<"No Subarray exist in this case"<<"\n";
    }
    else{
        cout<<"Minimum length subarray is "<<ans<<"\n";
    }
}