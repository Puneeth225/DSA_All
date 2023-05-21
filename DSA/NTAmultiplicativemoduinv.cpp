//(A*B)%m = 1, find B such that this condition satisfy
//is satisfied if gcd(A,m) = 1
//ax+by = gcd(a,b)  =>b=m
#include<bits/stdc++.h>
using namespace std;
struct triplet{
    int x,y,gcd;
};
triplet extendEuclid(int a,int b){
    if(b==0){
        triplet ans;
        ans.x = 1;
        ans.gcd = a;
        ans.y = 0;
        return ans;
    }
    triplet tempans = extendEuclid(b,a%b);
    triplet ans;
    ans.gcd = tempans.gcd;
    ans.x = tempans.y;
    ans.y = tempans.x-(a/b)*tempans.y;
    return ans;
}
int multiplicativemoduloinverse(int a,int m){
    triplet temp = extendEuclid(a,m);
    return temp.x;
}
int main(){
    int a,m;
    cin>>a>>m;
    cout<<multiplicativemoduloinverse(a,m)<<"\n";
}