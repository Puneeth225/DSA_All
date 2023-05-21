#include<bits/stdc++.h>
using namespace std;
int paintrreq(int bordlenth[],int n,int minpaintr){
    int sum = 0,paintrs= 1;
    for(int i=0;i<n;i++){
        sum += bordlenth[i];
        if(sum>minpaintr){
            sum = bordlenth[i];
            paintrs++;
        }
    }
    return paintrs;
}
int mintimetopaint(int bordlenth[],int n,int m){
    int totalboardlenth = 0,k=0;
    for(int i=0;i<n;i++){
        k = max(k,bordlenth[i]);
        totalboardlenth = totalboardlenth+bordlenth[i];
    }
    int low = k,high = totalboardlenth;
    while(low<high){
        int mid = (low+high)/2;
        int noofpainter = paintrreq(bordlenth,n,mid);
        if(noofpainter<=m){
            high = mid;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}
int main(){
    int arr[] = {10,20,30,40};
    int n = 4,m = 2;
    cout<<"Minimum time to paint: "<<mintimetopaint(arr,n,m)<<"\n";
}