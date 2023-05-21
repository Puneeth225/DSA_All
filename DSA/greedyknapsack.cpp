#include <bits/stdc++.h>
using namespace std;
//given the items and values and bag size fill the items such that they have maximum value
//items can be divided and remaning weight can be filled
bool compare(pair<int,int>p1, pair<int,int>p2){
    double valperunitwt1 = (double)p1.first/p1.second;
    double valperunitwt2 = (double)p2.first/p2.second;
    return valperunitwt1> valperunitwt2;
}
int main(){
    int n,w;
    cin>>n;
    cin>>w;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first>>a[i].second;
    }
    sort(a.begin(),a.end(),compare);
    int ans =0;
    for(int i=0;i<n;i++){
        if(w>=a[i].second){
            ans = ans+a[i].first;
            w = w-a[i].second;
            continue;
        }
        double valperunitwt = (double) a[i].first/a[i].second;
        ans += valperunitwt * w;
        w = 0;
        break;
    }
    cout<<ans<<"\n";
}