//connected components are those where two graphs are there in single graph such that those two are not connected to each other by any vertex of graph
#include <bits/stdc++.h>
using namespace std;
vector<bool> visited;
int n,m;
vector<vector<int>> adjlist;
vector<int> components;
int get_component(int val){
    if(visited[val]){
        return 0;
    }
    visited[val] = true;
    int ans = 1;
    for(auto i: adjlist[val]){
        if(!visited[i]){
            ans+=get_component(i);
            visited[i] = true;
        }
    }
    return ans;
}
int main(){
    cin>>n>>m;
    adjlist = vector<vector<int>>(n);
    visited = vector<bool>(n,false);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(!visited[i]){
            components.push_back(get_component(i));
        }
    }
    for(auto i: components){
        cout<<i<<" ";
    }cout<<"\n";
    //given n friends 0 to n-1 and select no of ways of selecting non connected friends
    long long ways = 0;
    for(auto i: components){
        ways += i*(n-i);
    }
    cout<<ways/2<<"\n";
}