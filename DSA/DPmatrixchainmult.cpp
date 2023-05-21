//given n 2D-matrix sizes find the way which requires minimum no of operations reqiured to compute the product of matrices
//for eg:  given a = [ , , , , , ] is array of sizes whose ith matrix size is a[i-1]*a[i] 
//if matrices a*b and b*c are multiplied it requires a*b*c operations


//memoization
#include<bits/stdc++.h>
using namespace std;
const int N = 200, MOD = 1e9+1;
int a[N];
int dp[N][N];
int matrix_chainmult(int i, int j){
    if(i==j){
        return 0; // as no matrix possible as size is size is a[i-1]*a[i] but if i==j results a[i]
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j] = MOD;
    for(int k=i;k<j;k++){
        dp[i][j] = min(dp[i][j],matrix_chainmult(i,k)+matrix_chainmult(k+1,j)+a[i-1]*a[k]*a[j]);//divides till k and further divide in left and right sub parts
    }
    return dp[i][j];
}
int main(){
    for(int i=0;i<N;i++){
        for(int j =0;j<N;j++){
            dp[i][j] = -1;
        }
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<matrix_chainmult(1,n-1)<<"\n";
}




//tabulation
// #include<bits/stdc++.h>
// using namespace std;
// const int N = 200, MOD = 1e9+1;
// int a[N];
// int dp[N][N];
// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     for(int i=0;i<n;i++){
//         dp[i][i] = 0;
//     }
//     for(int l=2;l<n;l++){
//         for(int i=1;i<n-l+1;i++){
//             int j= i+l-1;
//             dp[i][j] = MOD;
//             for(int k=i;k<j;k++){
//                 dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+(a[i-1]*a[k]*a[j]));
//             }
//         }
//     }
//     cout<<dp[1][n-1]<<"\n";
// }