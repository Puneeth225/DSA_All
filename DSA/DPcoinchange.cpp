//given a set of coins and make change(khulle) of given number X from given set and find number of ways to do so
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+2;
int dp[N][N];
// without DP
// int coinchange(vector<int> &a, int n, int x){
//     if(x == 0){
//         return 1; //if value is 0 no coin is taken
//     }
//     if(x<0){
//         return 0; //negative value given as x(given number)
//     }
//     if(n<=0){
//         return 0; //all coins used
//     }
//     return coinchange(a,n,x-a[n-1])+ coinchange(a,n-1,x); //coin taken + coin not taken
// }



// with DP
int coinchange(vector<int> &a, int n, int x){
    if(x == 0){
        return 1; //if value is 0 no coin is taken
    }
    if(x<0){
        return 0; //negative value given as x
    }
    if(n<=0){
        return 0; //all coins used
    }
    if(dp[n][x]!=-1){
        return dp[n][x];
    }
    dp[n][x] = coinchange(a,n,x-a[n-1])+ coinchange(a,n-1,x);
    return dp[n][x];
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j] = -1;
        }   
    }
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int x;
    cin>>x;
    cout<<coinchange(a,n,x)<<"\n";
}



//bottom up approach
// int main(){
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     int x;
//     cin>>x;
//     vector<vector<int>> dp(n+1,vector<int>(x+1,0));
//     dp[0][0] = 1;
//     for(int i=1;i<n+1;i++){
//         for(int j=0;j<x+1;j++){
//             if(j-a[i-1]>=0){
//                 dp[i][j] +=dp[i][j-a[i-1]];
//             }
//             dp[i][j] += dp[i-1][j];
//         }
//     }
//     cout<<dp[n][x];
// }