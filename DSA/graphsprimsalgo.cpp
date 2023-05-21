#include <bits/stdc++.h>
using namespace std;
int n,m,cost=0;
const int N= 1e5+1;
vector<vector<int>> adjlist[N];
vector<int> dist(n),parent(n);
vector<bool> visited(n);
const int INF = INT_MAX;
void primsalgo(int src){
    for(int i=0;i<n;i++){
        dist[i] = INF;
    }
    set<vector<int>> s;
    dist[src] = 0;
    s.insert({0,src});
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(x);
        visited[x[1]] = true;
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout<<u<<" "<<v<<" "<<w<<"\n";
        cost+=w;
        for(auto it: adjlist[x[1]]){
            if(visited[it[0]]){
                continue;
            }
            if(dist[it[0]]>it[1]){
                s.erase({dist[it[0]],it[0]});
                dist[it[0]] = it[1];
                s.insert({dist[it[0]],it[0]});
                parent[it[0]] = x[1];
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adjlist[u].push_back({v,w});
        adjlist[v].push_back({u,w});
    }
    primsalgo(0);
    cout<<cost<<"\n";
}