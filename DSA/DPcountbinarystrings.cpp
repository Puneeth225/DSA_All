//given a number n and find no of binary strings of length n which do not contain consecutive ones
//this is same as fibonacci series as one[i] = zero[i-1] and zero[i] = one[i-1]+zero[i-1] = zero[i-2]+zero[i-1]
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+5;
int dp[N];
int fib(int n){
    if(n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = fib(n-1)+fib(n-2);
    return dp[n];
}
int main(){
    for(int i=0;i<N;i++){
        dp[i] = -1;
    }
    int n;
    cin>>n;
    cout<<fib(n+1)<<"\n";
}