//given a number n find the minimum number of numbers required to compute n as sum of squares
//26 = 3^2+4^2+1^1 and 26 = 5^2+1^1 so minimum is 2
//without dynamic programming
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5+5, MOD = 1e9;
// int minimum_squaressum(int n){
//     if(n ==1||n==2||n==3||n==0){
//         return n;
//     }
//     int ans = MOD;
//     for(int i=1;i*i<=n;i++){
//         ans = min(ans,1+minimum_squaressum(n-i*i));
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<minimum_squaressum(n)<<"\n";
// }



//with dynamic
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5, MOD = 1e9;
int dp[N];
int minimum_squaressum(int n){
    if(n ==1||n==2||n==3||n==0){
        return n;
    }
    if(dp[n]!=MOD){
        return dp[n];
    }
    int ans = MOD;
    for(int i=1;i*i<=n;i++){
        dp[n] = min(dp[n],1+minimum_squaressum(n-i*i));
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<N;i++){
        dp[i] = MOD;
    }
    cout<<minimum_squaressum(n)<<"\n";
}


//with bottom up approach
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5+5, MOD = 1e9;
// int main(){
//     int n;
//     cin>>n;
//     vector<int> dp(n+1,MOD);
//     dp[0] = 0;
//     dp[1] = 1;
//     dp[2] = 2;
//     dp[3] = 3;
//     for(int i=1;i*i<=n;i++){
//         for(int j=0;i*i+j<=n;j++){
//             dp[i*i+j] = min(dp[i*i+j],1+dp[j]);
//         }
//     }
//     cout<<dp[n]<<"\n";
// }