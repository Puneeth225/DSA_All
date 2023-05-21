//given two strings and find the length of longest common subsequence in both strings
//normal way
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5+2, MOD = 1e9+7;
// int longest_comon_subseq(string &s1, string &s2,int n, int m){
//     if(n==0||m==0){
//         return 0;
//     }
//     if(s1[n-1]==s2[m-1]){
//         return 1+longest_comon_subseq(s1,s2,n-1,m-1);//both last chars are removed making one increase in common subseq length
//     }
//     else{
//         return max(longest_comon_subseq(s1,s2,n,m-1),longest_comon_subseq(s1,s2,n-1,m));//remove last char from each string and check max
//     }
// }
// int main(){
//     string s1,s2;
//     cin>>s1>>s2;
//     int l1 = s1.size(), l2 = s2.size();
//     cout<<longest_comon_subseq(s1,s2,l1,l2)<<"\n";
// }



//memoization
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+2, MOD = 1e9+7;
int dp[N][N];
int longest_comon_subseq(string &s1, string &s2,int n, int m){
    if(n==0||m==0){
        return 0;
    }
    if(dp[n][m]!= -1){
        return dp[n][m];
    }
    if(s1[n-1]==s2[m-1]){
        dp[n][m] = 1+longest_comon_subseq(s1,s2,n-1,m-1);//both last chars are removed making one increase in common subseq length
    }
    else{
        dp[n][m] = max(longest_comon_subseq(s1,s2,n,m-1),longest_comon_subseq(s1,s2,n-1,m));//remove last char from each string and check max
    }
    return dp[n][m];
}
int main(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            dp[i][j] = -1;
        }
    }
    string s1,s2;
    cin>>s1>>s2;
    int l1 = s1.size(), l2 = s2.size();
    cout<<longest_comon_subseq(s1,s2,l1,l2)<<"\n";
}



//tabulation bottom up approach
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e3+2, MOD = 1e9+7;
// int main(){
//     string s1,s2;
//     cin>>s1>>s2;
//     int l1 = s1.size(), l2 = s2.size();
//     vector<vector<int>> dp(l1+1,vector<int>(l2+1,-1));
//     for(int i=0;i<l1+1;i++){
//         for(int j=0;j<l2+1;j++){
//             if(i==0||j==0){
//                 dp[i][j] =0;
//                 continue;
//             }
//             if(s1[i-1] == s2[j-1]){
//                 dp[i][j] = 1+dp[i-1][j-1];
//             }
//             else{
//                 dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//             }
//         }
//     }
//     cout<<dp[l1][l2]<<"\n";
// }



