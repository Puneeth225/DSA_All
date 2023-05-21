//given an array take K elements from it such that min dist between those k elements in pairs is maximum
#include<bits/stdc++.h>
using namespace std;
bool ispossiblek(int mid,int arr[],int n, int k){
    int initial = arr[0], noofelements = 1;
    for(int i=1;i<n;i++){
        if(arr[i]-initial>=mid){
            initial = arr[i];
            noofelements++;
            if(noofelements == k){
                return true;
            }
        }
    }
    return false;
}
int biggestmindist(int arr[],int n,int k){
    sort(arr,arr+n);
    int ans = -1;
    int left = arr[0], right = arr[n-1];
    while (left<right)
    {
        int mid = (left+right)/2;
        if(ispossiblek(mid,arr,n,k)){
            ans = max(ans,mid);
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    return ans;
    
}
int main(){
    int a[] = {1,2,4,8,9};
    int n=5,k=2;
    cout<<biggestmindist(a,n,k)<<"\n";
}