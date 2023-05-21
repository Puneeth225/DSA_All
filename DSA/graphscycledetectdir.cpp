//detect a cycle in directed graph
#include <bits/stdc++.h>
using namespace std;
bool iscycle(int src, vector<vector<int>> &adjlist, vector<bool> &visited,vector<bool> &sstack){
    sstack[src] = true;
    if(!visited[src]){
        visited[src] = true;
        for(auto i: adjlist[src]){
            if(!visited[i] && iscycle(i,adjlist,visited,sstack)){
                return true;
            }
            if(sstack[i]){
                return true;
            }
        }
    }
    sstack[src] = false;
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
    }
    bool cycle = false;
    vector<bool> sstack(n,0);
    vector<bool> visited(n,0);
    for(int i=0;i<n;i++){
        if(!visited[i] && iscycle(i,adjlist,visited,sstack)){
            cycle = true;
        }
    }
    if(cycle){
        cout<<"Cycle is Present"<<"\n";
    }
    else{
        cout<<"Cycle NOT Present"<<"\n";
    }
}