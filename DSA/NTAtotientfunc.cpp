//f(n) = n*(1-1/p1)*(1-1/p2)*...(1-1/pk)
//p1,p2,...pk are prime factors of n
//f(a*b) = f(a)*f(b) if a,b are coprimes
//sieve of erasthothenes
#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+2, MOD = 1e9+9;
int totient[N];
int main(){
    for(int i=0;i<N;i++){
        totient[i] = i;
    }
    for(int i=2;i<N;i++){
        if(totient[i] == i){
            for(int j=2*i;j<N;j+=i){
                totient[j]*=(i-1);
                totient[j]/=i;
            }
            totient[i] =(i-1);
        }
    }
    for(int i=2;i<11;i++){
        cout<<totient[i]<<" ";
    }
}