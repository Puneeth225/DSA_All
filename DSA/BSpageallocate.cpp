//for students 'm' there are 'n' pages of 'n' diff books distribute pages to 'm' students such that maximum number of pages for a student is minimum
#include<bits/stdc++.h>
using namespace std;
bool candistribute(int arr[],int n,int m,int currmin){
    int studreq =1, sum = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>currmin){
            return false;
        }
        if(sum+arr[i]>currmin){
            studreq++;
            sum = arr[i];
            if(studreq>m){
                return false;
            }
        }
        else{
            sum+=arr[i];
        }
    }
    return true;
}
int distributeminpages(int arr[],int n, int m){
    int sum = 0;
    if(n<m){
        return -1;
    }
    for(int i=0;i<n;i++){
        sum = sum+arr[i];
    }
    int start = 0,end = sum,ans = INT_MAX;
    while(start<=end){
        int mid = (start+end)/2;
        if(candistribute(arr,n,m,mid)){
            ans = min(ans,mid);
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;
}
int main(){
    int arr[] = {12,34,67,90};
    int n=4,m=2;
    cout<<"Minimum Number of pages: "<<distributeminpages(arr,n,m)<<"\n";
}