#include<bits/stdc++.h>
using namespace std;
int searchinrotated(int arr[],int key, int left, int right){
    if(left>right){
        return -1;
    }
    int mid = (left+right)/2;
    if(arr[mid] == key){
        return mid;
    }
    if(arr[left]<=arr[mid]){
        if(key>=arr[left]&&key<=arr[mid]){
            return searchinrotated(arr,key,left,mid-1);
        }
        return searchinrotated(arr,key,mid+1,right);
    }
    if(key>=arr[mid]&&key<=arr[right]){
        return searchinrotated(arr,key,mid+1,right);
    }
    return searchinrotated(arr,key,left,mid-1);
}
int main(){
    int a[] = {10,20,30,40,50,1,2,5,8,9};
    int n = 10,key = 2;
    int idx = searchinrotated(a,key,0,n-1);
    if(idx == -1){
        cout<<"Key doesn't exist"<<"\n";
    }
    else{
        cout<<"Key at: "<<idx+1<<"\n";
    }
}