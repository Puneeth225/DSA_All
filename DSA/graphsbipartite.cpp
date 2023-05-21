//bipartite is if your current vertex is red colour then its neighbours are blue and if such colouring is done it is bipartite
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adjlist;
vector<bool> visited;
vector<int> color;
bool bipart;
void colorassign(int u,int curr){
    if(color[u] != -1 && color[u] != curr){
        bipart = false;
        return;
    }
    color[u] = curr;
    if(visited[u]){
        return;
    }
    visited[u] = true;
    for(auto i: adjlist[u]){
        colorassign(i,!curr);   //(!curr) or you can use (curr xor 1)
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    bipart = true;
    adjlist = vector<vector<int>>(n);
    visited = vector<bool>(n,false);
    color = vector<int>(n,-1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            colorassign(i,0);
        }
    }
    if(bipart){
        cout<<"Graph is Bipartite"<<"\n";
    }
    else{
        cout<<"Graph is not Bipartite"<<"\n";
    }
}