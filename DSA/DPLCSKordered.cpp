//given two arrays find length of longest common subsequence by changing K positions in 1st string to maximize len of common subseq
// #include<bits/stdc++.h>
// using namespace std;
// int n,m,k;
// vector<int> a;
// vector<int> b;
// int findLCS(int i,int j,int k){
//     if(i==n||j==m){
//         return 0;
//     }
//     int c1(0),c2(0),c3(0);
//     if(a[i] == b[j]){
//         c1 = 1+findLCS(i+1,j+1,k);
//     }
//     if(k>0){
//         c2 = 1+findLCS(i+1,j+1,k-1);
//     }
//     c3 = max(findLCS(i+1,j,k),findLCS(i,j+1,k));
//     return  max({c1,c2,c3});
// }
// int main(){
//     cin>>n>>m>>k;
//     a = vector<int>(n);
//     b = vector<int>(m);
//     for(auto &i:a){
//         cin>>i;
//     }
//     for(auto &i:b){
//         cin>>i;
//     }
//     cout<<findLCS(0,0,k)<<"\n";
// }






//memoization
#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> a;
vector<int> b;
int dp[2022][2022][10];
int findLCS(int i,int j,int k){
    if(i==n||j==m){
        return 0;
    }
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    int c1(0),c2(0),c3(0);
    if(a[i] == b[j]){
        c1 = 1+findLCS(i+1,j+1,k);
    }
    if(k>0){
        c2 = 1+findLCS(i+1,j+1,k-1);
    }
    c3 = max(findLCS(i+1,j,k),findLCS(i,j+1,k));
    return dp[i][j][k] = max({c1,c2,c3});
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k;
    a = vector<int>(n);
    b = vector<int>(m);
    for(auto &i:a){
        cin>>i;
    }
    for(auto &i:b){
        cin>>i;
    }
    cout<<findLCS(0,0,k)<<"\n";
}