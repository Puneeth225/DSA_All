//detect a cycle in undirected graph
#include <bits/stdc++.h>
using namespace std;
bool iscycle(int src, vector<vector<int>> &adjlist, vector<bool> &visited, int parent){
    visited[src] = true;
    for(auto i: adjlist[src]){
        if(i!=parent){
            if(visited[i]){
                return true;
            }
            if(!visited[i] && iscycle(i,adjlist,visited,src)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adjlist(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    bool cyclethere = false;
    vector<bool> visited(n,false);
    for(int i=0;i<n;i++){
        if(!visited[i] && iscycle(i,adjlist,visited,-1)){
            cyclethere = true;
        }
    }
    if(cyclethere){
        cout<<"Cycle is present"<<"\n";
    }
    else{
        cout<<"NO Cycle is there"<<"\n";
    }
}