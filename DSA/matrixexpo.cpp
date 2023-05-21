//to find fibonacci in O(log n)
//f(n)/f(n-1)   == ({{1,1},{1,0}}^n-2) *(f(2)/f(1))
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+1,MOD = 1e9+9;
//multiplying two square matrices
vector<vector<int>> multiply(vector<vector<int>>&a,vector<vector<int>>&b){
    int n= a.size();
    vector<vector<int>>ans(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                ans[i][j] +=a[i][k]*b[k][j];
            }
        }
    }
    return ans;
}
//function to exponentiate
vector<vector<int>> matrixexp(vector<vector<int>>&a,int n){
    if(n==0){
        int sz = a.size();
        vector<vector<int>> ans(sz,vector<int>(sz,0));
        for(int i=0;i<sz;i++){
            ans[i][i] =1;
        }
        return ans;
    }
    if(n==1){
        return a;
    }
    //if n is even
    vector<vector<int>>temp = matrixexp(a,n/2);
    vector<vector<int>> ans = multiply(temp,temp);
    //if n is odd a^n = a^(n/2)*a^(n/2)*a
    if(n&1){
        ans = multiply(ans,a);
    }
    return ans;
}
int32_t main(){
    int n;
    cin>>n; // nth fibonacci number is ans[0][1] and ans[1][0] term in ans matrix
    vector<vector<int>> a = {{1,1},{1,0}};
    vector<vector<int>>ans = matrixexp(a,n);//if matrixexp(a,n-2) then multiply with matrix {{1},{1}} to get f(n)/f(n-1)
    int sz = ans.size();
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}