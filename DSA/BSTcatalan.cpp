#include<bits/stdc++.h>
using namespace std;
int catalan(int n){
    if(n<=1){
        return 1;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += catalan(i) * catalan(n-i-1);
    }
    return ans;
}
int main(){
    int num;
    cout<<"Enter how many catalans you need : ";
    cin>>num;
    for(int i=0;i<num;i++){
        cout<<catalan(i)<<" ";
    }
    cout<<"\n";
}
