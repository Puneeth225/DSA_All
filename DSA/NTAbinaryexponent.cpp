//given two numbers a,n find a^n, as it can be large find mod of it
//convert n into binary
//iterative
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int N = 1e5+2;
// const int MOD = 1e9+7;
// int binexp(ll a,ll n){
//     a = a%MOD;
//     ll ans = 1;
//     while(n>0){
//         if(n&1){
//             ans = (ans*a)%MOD;
//         }
//         a = (a*a)%MOD;
//         n= n>>1;
//     }
//     return ans;
// }
// int main(){
//     ll a,n;
//     cin>>a>>n;
//     cout<<binexp(a,n)<<"\n";
// }



//recursive
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5+2;
const int MOD = 1e9+7;
int binexp(ll a,ll n){
    a = a%MOD;
    if(n==0){
        return 1;
    }
    int p = binexp(a,n/2)%MOD;
    if(n&1){
        return (((p*p)%MOD)*a)%MOD;
    }
    else{
        return (p*p)%MOD;
    }
}
int main(){
    ll a,n;
    cin>>a>>n;
    cout<<binexp(a,n)<<"\n";
}