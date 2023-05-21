//peak element is one which is greater then it's neighbours
#include<bits/stdc++.h>
using namespace std;
int peakelement(int arr[],int low, int high,int n){
    int mid = low+(high-low)/2;
    if((mid == 0||arr[mid-1]<=arr[mid])&&(mid == n-1||arr[mid+1]<=arr[mid])){
        return mid;
    }
    else if(mid>0 && arr[mid-1]>arr[mid]){
        return peakelement(arr,low,mid-1,n);
    }
    else{
        return peakelement(arr,mid+1,high,n);
    }

}
int main(){
    int a[] = {0,6,8,5,7,9};
    int n=6;
    cout<<"Peak element is at index: "<<peakelement(a,0,n-1,n)<<" ,and element is "<<a[peakelement(a,0,n-1,n)]<<"\n";
}