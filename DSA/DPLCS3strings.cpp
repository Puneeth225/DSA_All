//given 3 strings find the length of longest common subsequence in all 3
// #include<bits/stdc++.h>
// using namespace std;
// int LCS(string &s1,string &s2, string &s3,int i,int j,int k){
//     if(i == 0||j==0||k==0){
//         return 0;
//     }
//     if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]){
//         return 1+LCS(s1,s2,s3,i-1,j-1,k-1);
//     }
//     int l = LCS(s1,s2,s3,i-1,j,k);
//     int m = LCS(s1,s2,s3,i,j-1,k);
//     int n = LCS(s1,s2,s3,i,j,k-1);
//     return max({l,m,n});
// }
// int main(){
//     string s1,s2,s3;
//     cin>>s1>>s2>>s3;
//     int a = s1.size(),b= s2.size(),c = s3.size();
//     cout<<LCS(s1,s2,s3,a,b,c);
// }





//memoization
#include<bits/stdc++.h>
using namespace std;
int dp[210][210][210];
int LCS(string &s1,string &s2, string &s3,int i,int j,int k){
    if(i == 0||j==0||k==0){
        return 0;
    }
    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }
    if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]){
        return dp[i][j][k] =  1+LCS(s1,s2,s3,i-1,j-1,k-1);
    }
    int l = LCS(s1,s2,s3,i-1,j,k);
    int m = LCS(s1,s2,s3,i,j-1,k);
    int n = LCS(s1,s2,s3,i,j,k-1);
    return dp[i][j][k] = max({l,m,n});
}
int main(){
    memset(dp,-1,sizeof(dp)); //it initializes dp by -1, total size of dp is replaced by -1
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int a = s1.size(),b= s2.size(),c = s3.size();
    cout<<LCS(s1,s2,s3,a,b,c);
}