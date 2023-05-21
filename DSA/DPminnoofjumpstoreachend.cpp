//given an array of numbers each number denote the max of jumps one can make from that position find if minimum jumps to reach end
//using DP is done by o(n^2) but by greedy it is done in o(n)
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9+1;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr){
        cin>>i;
    }
    vector<int> jumps(n,INF);
    if(arr[0] == 0){
        //cout<<"Not Possible"<<"\n";//as one can't start
        cout<<"-1"<<"\n";
    }
    jumps[0] = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(i<=(j+arr[j])){
                jumps[i] = min(jumps[i],jumps[j]+1);
            }
        }
    }
    cout<<jumps[n-1]<<"\n";
}