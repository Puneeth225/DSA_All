#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5, MOD = 1e9;
int dp[N];
int fib(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 0;
    }
    if(n == 2){
        return 1;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = fib(n-1) + fib(n-2);
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<N;i++){
        dp[i] = -1;
    }
    cout<<fib(n)<<"\n";
}


// int main(){
//     int n;
//     cin>>n;
//     vector<int> dp1(n+1);
//     dp1[0] = 0;
//     dp1[1] = 0;
//     dp1[2] = 1;
//     for(int i=3;i<=n;i++){
//         dp1[i] = dp1[i-1] + dp1[i-2];
//     }
//     cout<<dp1[n]<<"\n";
// }