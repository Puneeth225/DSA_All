#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+1;
bool visited[N];
vector<int> adjlist[N];
void dfs(int node){
    //preorder
    visited[node] = 1;
    
    cout<<node<<" ";
    //inorder
    vector<int> :: iterator it;
    for(it = adjlist[node].begin();it!=adjlist[node].end();it++){
        if(visited[*it]){}
        else{
            dfs(*it);
        }
    }
    // for(auto it: adjlist[node]){
    //     if(visited[it]){}
    //     else{
    //         dfs(it);
    //     }
    // }
    //postorder
    //cout<<node<<" ";
}
int main(){
    int n,m;
    cin>>n>>m;
    int x,y;
    for(int i=0;i<N;i++){
        visited[i] = 0;
    }
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    dfs(1);

}







