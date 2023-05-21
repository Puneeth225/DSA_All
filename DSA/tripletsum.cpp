//find sum of 3 elements equal to target
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,i,lo,hi;
    cout<<"Enter the required-"<<"\n";
    cin>>n;
    int finalsum;
    cin>>finalsum;
    bool found = false;
    vector<int> a(n);
    for(auto &i: a){
        cin>>i;
    }

    sort(a.begin(),a.end());
    for( i=0;i<n;i++){
        lo = i+1, hi=n-1;
        while(lo<hi){
            int currsum = a[i]+a[lo]+a[hi];
            if(currsum == finalsum){
                found = true;
            }
            if(currsum<finalsum){
                lo++;
            }
            else{
                hi--;
            }
            
        }
    }
    if(found == true){
        cout<<"Triplet is there!"<<"\n";
    }
    else{
        cout<<"Not Found!!"<<'\n';
    }
}