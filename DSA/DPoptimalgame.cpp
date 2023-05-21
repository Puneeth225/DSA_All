//two players play a game and from a given array of coins with values on it and each player plays alternate find value of coins first started player can have if he wins and a player can pick either first or last coin only
// #include <bits/stdc++.h>
// using namespace std;
// vector<int> a;
// int solveoptimalgame(int i,int j){
//     if(i==j){
//         return a[i];
//     }
//     if(i>j){
//         return 0;
//     }
//     int ch1= a[i]+min(solveoptimalgame(i+2,j),solveoptimalgame(i+1,j-1));//if 1st player choose ith coin then 2nd can choose i+1th or jth and take minimum of i+2th and (j-1)th (choice1)
//     int ch2 = a[j]+min(solveoptimalgame(i+1,j-1),solveoptimalgame(i,j-2));//if 1st player choose jth coin (choice2)
//     return max(ch1,ch2);
// }
// int main(){
//     int n;
//     cin>>n;
//     a = vector<int>(n);
//     for(auto &i:a){
//         cin>>i;
//     }
//     cout<<solveoptimalgame(0,n-1);
// }




//memoization
#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int dp[1000][1000];
int solveoptimalgame(int i,int j){
    if(i==j){
        return a[i];
    }
    if(i>j){
        return 0;
    }
    if(dp[i][j] !=-1){
        return dp[i][j];
    }
    int ch1= a[i]+min(solveoptimalgame(i+2,j),solveoptimalgame(i+1,j-1));//if 1st player choose ith coin then 2nd can choose i+1th or jth and take minimum of i+2th and (j-1)th (choice1)
    int ch2 = a[j]+min(solveoptimalgame(i+1,j-1),solveoptimalgame(i,j-2));//if 1st player choose jth coin (choice2)
    dp[i][j] = max(ch1,ch2);
}
int main(){
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            dp[i][j] = -1;
        }
    }
    int n;
    cin>>n;
    a = vector<int>(n);
    for(auto &i:a){
        cin>>i;
    }
    cout<<solveoptimalgame(0,n-1);
}
