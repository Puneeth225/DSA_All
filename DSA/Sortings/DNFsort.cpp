#include<bits/stdc++.h>
using namespace std;
void swap(int arr[],int l,int h){
    int temp = arr[l];
    arr[l] = arr[h];
    arr[h] = temp;
}
void dnfsort(int arr[],int n){
    int l=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr,l,mid);
            l++;mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr,mid,high);
            high--;
        }
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dnfsort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}