//finding the length of maximum one's subarray by fliping k zeros to one
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, flipmax;
    cin>>n;
    cin>>flipmax;
    vector<int> a(n);
    for(auto &i:a){
        cin>>i;
    }
    int cn0=0,i=0,ans=0;
    for(int j=0;j<n;j++){
        if(a[j]==0){
            cn0++;
        }
        while(cn0>flipmax){
            if(a[i]==0){
                cn0--;
            }
            i++;
        }
        ans= max(ans,j-i+1);
    }
    cout<<ans<<"\n";
}