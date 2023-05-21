//given an array find the longest subsequence length which is increasing
//subarray ---> is continuous 
//subsequence ----> need not be continuous but order should be same



//memoization
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e5+2, MOD = 1e9+7;
// int dp[N];
// int longest_incre_subseq(vector<int> &a, int n){
//     if(dp[n]!=-1){
//         return dp[n];
//     }
//     dp[n] = 1; //single element sequence
//     for(int i=0;i<n;i++){
//         if(a[n]>a[i]){
//             dp[n] = max(dp[n],1+longest_incre_subseq(a,i));
//         }
//     }
//     return dp[n];
// }
// int main(){
//     for(int i=0;i<N;i++){
//         dp[i] = -1;
//     }
//     int n;
//     cin>>n;
//     vector<int> a(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     cout<<longest_incre_subseq(a,n-1)<<"\n";
// }



//tabulation bottom up build
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+2, MOD = 1e9+7;
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> dp(n,1);
    int seqlen = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[i]>a[j]){
                dp[i] = max(dp[i],1+dp[j]);
            }
        }
        seqlen = max(seqlen,dp[i]);
    }
    cout<<seqlen<<"\n";
}
