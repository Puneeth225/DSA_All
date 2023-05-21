//given a large number n and a prime number p find n!%p where abs(n-p)<=1000
#include<bits/stdc++.h>
using namespace std;
#define int long long
int binexp(int x,int y,int p){
    int res = 1;
    x = x%p;
    while(y>0){
        if(y&1){
            res = (res*x)%p;
        }
        y = y>>1;
        x = (x*x)%p;
    }
    return res;
}
int modinverse(int a,int p){
    return binexp(a,p-2,p);
}
int modfactn(int n,int p){
    if(p<=n){
        return 0;  //here n! has multiple of p so n!%p=0
    }
    int res = (p-1); // (p-1)! =~ p-1 mod p
    for(int i=n+1;i<p;i++){
        res = (res*modinverse(i,p))%p;
    }
    return res;
}
int32_t main(){
    int n,p;
    cin>>n>>p;
    cout<<modfactn(n,p)<<"\n";
}