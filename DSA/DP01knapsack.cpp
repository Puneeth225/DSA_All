//given the list of values and weights take items which sum to maximum value and sum of weights is less than knapsack capacity
//items cannot be divided
//without DP
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5+2, MOD = 1e9+1;
// int val[N],wt[N];
// int knapsack(int n,int w){
//     if(w<=0||n<=0){
//         return 0;
//     }
//     if(wt[n-1]>w){
//         return knapsack(n-1,w);
//     }
//     return max(knapsack(n-1,w),knapsack(n-1,w-wt[n-1])+val[n-1]);
// }
// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>wt[i];
//     }
//     for(int i=0;i<n;i++){
//         cin>>val[i];
//     }
//     int w;
//     cin>>w;
//     cout<<knapsack(n,w)<<"\n";
// }









//with DP
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+2, MOD = 1e9+1;
int val[N],wt[N];
int dp[N][N];
int knapsack(int n,int w){
    if(w<=0||n<=0){
        return 0;
    }
    if(dp[n][w] != -1){
        return dp[n][w];
    }
    if(wt[n-1]>w){
        dp[n][w] = knapsack(n-1,w);
    }
    dp[n][w] = max(knapsack(n-1,w),knapsack(n-1,w-wt[n-1])+val[n-1]);
    return dp[n][w];
}
int main(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j] = -1;
        }
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    int w;
    cin>>w;
    cout<<knapsack(n,w)<<"\n";
}