//Number Theory Advanced
//diophantine eqns
//find integral solutions for eqn of form ax+by = 1
//ax+by=c is made ax+by=1 if c divides a,b i.e. c is GCD of a,b
//gcd(a,b) = gcd(b,a%b),,ax+by = gcd(a,b)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct triplet
{
    int x,y,gcd;
};
triplet extendedeuclidalgo(int a,int b){
    if(b==0){
        triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;  //ax = gcd(a,b) = a  ==>x==1 & y=0
    }
    triplet tempans = extendedeuclidalgo(b,a%b);
    triplet ans;
    ans.gcd = tempans.gcd;
    ans.x = tempans.y;
    ans.y = tempans.x-(a/b)*tempans.y;
    return ans;
}
int main(){
    int a,b;
    cin>>a>>b;
    triplet ans = extendedeuclidalgo(a,b);
    cout<<ans.gcd<<" "<<ans.x<<" "<<ans.y<<"\n";
}