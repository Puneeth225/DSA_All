//given an array of size n and find a subarray of size k such that maximum perfect numbers are there
// perfect numbers are whose sum of divisors is equal to number itself
// 6 = 1+2+3
#include<bits/stdc++.h>
using namespace std;
int maxsum(int arr[],int n,int k){
    if(n<k){
        cout<<"Wrong inputs."<<"\n";
        return -1;
    }
    int ones = 0;
    for(int i=0;i<k;i++){
        ones +=arr[i];
    }
    int maxones = ones;
    for(int i=k;i<n;i++){
        maxones = maxones+arr[i] - arr[i-k];
        ones  = max(maxones,ones);
    }
    return ones;
}
bool isperfect(int n){
    int sum = 1;
    for(int i=2;i<sqrt(n);i++){
        if(n%i == 0){
            if(i ==n/i){
                sum = sum+i;
            }
            else{
                sum = sum+i+(n/i);
            }
        }
    }
    if(sum ==n && n!= 1){
        return true;
    }
    return false;
}
int maxperfects(int arr[],int n,int k){
    for(int i=0;i<n;i++){
        if(isperfect(arr[i])){
            arr[i] = 1;
        }
        else{
            arr[i] = 0;
        }
    }
    return maxsum(arr,n,k);
}
int main(){
    int arr[] = {28,2,3,6,496,99,8128,24};
    int k=4;
    int n=8;
    cout<<maxperfects(arr,n,k)<<"\n";
}