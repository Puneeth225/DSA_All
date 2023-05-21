#include <bits/stdc++.h>
using namespace std;
// if cycle there in graph no topological sort is possible
int main(){
    int n,m,cnt=0;
    cin>>n>>m;
    vector<vector<int>> adjlist(n);
    vector<int> indeg(n,0); //0 assigns all values to zero
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;   //u-->v
        adjlist[u].push_back(v);
        indeg[v]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(indeg[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        cnt++;
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        for(auto it: adjlist[x]){
            indeg[it]--;
            if(indeg[it] == 0){
                q.push(it);
            }
        }
    }
}