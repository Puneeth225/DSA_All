//given start and end times of an activity find the maximum activities we can perform
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,starttime,endtime;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++){
        cin>>starttime>>endtime;
        v.push_back({starttime,endtime});
    }
    sort(v.begin(),v.end(),[&](vector<int> &a,vector<int> &b){
        return a[1]<b[1];  //it is custom parameter that compares end times of a and b and arranges in ascending order
    });
    int take = 1;
    int end = v[0][1];
    for(int i=1;i<n;i++){
        if(v[i][0]>=end){  //if start time of other activity is greater than end time of first activity then take++ and end is end time of new activity
            take++;
            end = v[i][1];
        }
    }
    cout<<take<<"\n";
}