// given an array of size n and subarray of size k find if there exists a subarray of size k such that it is palindromic
#include<bits/stdc++.h>
using namespace std;
bool ispalindrome(int n){
    int temp = n,rev = 0;
    while(temp>0){
        rev = rev*10 + temp%10;
        temp = temp/10;
    }
    if(rev == n){
        return true;
    } 
    return false;
}
int palindromicsubarray(vector<int> arr,int k){
    int num = 0;
    for(int i=0;i<k;i++){
        num = num*10 + arr[i];
    }
    if(ispalindrome(num)){
        return 0;
    }
    for(int i=k;i<arr.size();i++){
        num = num % (int)pow(10,k-1)*10+arr[i];
        if(ispalindrome(num)){
            return i-k+1;
        }
    }
    return -1;
}
int main(){
    vector<int> a = {2,3,5,1,1,5};
    int k = 4;
    int ans = palindromicsubarray(a,k);
    if(ans == -1){
        cout<<"Such Palindromic subarray is not there"<<"\n";
    }
    else{
        for(int i=ans;i<ans+k;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}