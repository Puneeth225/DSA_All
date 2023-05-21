//minimum spanning tree(cost is minimum) finding by kruskal's algo
//it returns cost of tree i.e. sum of edges weights of spanning tree
#include <bits/stdc++.h>
using namespace std;
const int N= 1e5+1;
vector<int> parent(N);
vector<int> sizeofset(N);
void make_set(int vertex){
    parent[vertex] = vertex;
    sizeofset[vertex] = 1;
}
int find_set(int vertex){
    if(vertex == parent[vertex]){
        return vertex;
    }
    return parent[vertex] = find_set(parent[vertex]);
}
void union_set(int v1, int v2){
    v1 = find_set(v1);
    v2 = find_set(v2);
    if(v1!=v2){
        if(sizeofset[v1]<sizeofset[v2]){
            swap(v1,v2);
        }
        parent[v2] = v1;
        sizeofset[v1] += sizeofset[v2];
    }
}
int main(){
    for(int i=0;i<N;i++){
        make_set(i);
    }
    int n,m,cost=0;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());  //sort according to weight
    for(auto i:edges){
        int w = i[0];
        int u = i[1];
        int v = i[2];
        int x = find_set(u);
        int y = find_set(v);
        if(x == y){
            continue;
        }
        else{
            cout<<u<<" "<<v<<"\n";
            cost += w;
            union_set(u,v);
        }
    }
    cout<<cost<<"\n";
}
