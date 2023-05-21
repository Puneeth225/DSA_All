//detect cycle using disjoint set union, if from different subset we union them and make parent and finally add small size graph to large
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
    int n,m;
    bool cycle = false;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }
    for(auto i:edges){
        int edgev1 = i[0];
        int edgev2 = i[1];
        int x= find_set(edgev1);
        int y = find_set(edgev2);
        if(x == y){
            cycle = true;
        }
        else{
            union_set(edgev1,edgev2); // or can use union_set(x,y) and in union set function remove starting two lines
        }
    }
    if(cycle){
        cout<<"Cycle is there."<<"\n";
    }
    else{
        cout<<"Cycle Not there."<<"\n";
    }
}
