#include <bits/stdc++.h>
using namespace std;
const int N= 1e5+1;
vector<int> parent(N);
vector<int> sizeofset(N);
int main(){
    // int n,m,cost=0;
    // cin>>n>>m;
    // vector<vector<int>> edges;
    // for(int i=0;i<m;i++){
    //     int u,v,w;
    //     cin>>u>>v>>w;
    //     edges.push_back({w,u,v});
    // }
    // sort(edges.begin(),edges.end());
    // for(auto it:edges){
    //     cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<"\n";
    // }
    if(-1>-1){
        cout<<"True";
    }
    else{
        cout<<"NO";
    }
}





//  int isNegativeWeightCycle(int n, vector<vector<int>>edges){
//    vector<int>dist(n,1e8);
//       dist[0]=0;
//    for(int i=0; i<n-1; i++){
//        for(auto v:edges){
//            if(dist[v[1]]>dist[v[0]]+v[2]){
//                dist[v[1]]=dist[v[0]]+v[2];
//            }
//        }
//    }
//    for(auto v:edges){
//   if(dist[v[0]]+v[2]<dist[v[1]])
//             return 1;
//    }
//    return 0;
// }

// int main(){
//     int n = 3;
//     vector<vector<int>>edges = {{0,1,-1},{1,2,-2},{2,0,-3}};
//     int ans = isNegativeWeightCycle(n,edges);
//     cout<<ans;
// }