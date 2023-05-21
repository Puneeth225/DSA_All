#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    const int N = 1e5+2;
    //-----------Adjacency Matrix-------------//
    int n,m;
    cin>>n>>m; // m-edges n-nodes
    vector<vector<int>> mat2D(n+1,vector<int>(n+1,0)); //graphs are defined by 2D matrices
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        mat2D[x][y] = 1;
        mat2D[y][x] = 1;
    }
    
    cout<<"Adjacency matrix : "<<"\n";
    for(int i=1;i<=n;i++){
        for(int j= 1;j<=n;j++){
            cout<<mat2D[i][j]<<" ";
        }cout<<"\n";
    }
    if(mat2D[1][2]==1){
        cout<<"Edge is present between 1 and 2"<<"\n";
    }
    else{
        cout<<"NO Edge"<<"\n";
    }
    //-----------Adjacency List-------------//
    int n1,m1;// shows which node is connected to which other nodes
    cin>>n1>>m1;
    vector<int> adjlist[N];
    for(int i=0;i<m1;i++){
        int x,y;
        cin>>x>>y;
        adjlist[x].push_back(y);
        adjlist[y].push_back(x);
    }
    cout<<"Adjacency List is: "<<"\n";
    for(int i=1;i<=n1;i++){
        cout<<i<<" => ";
        vector<int> :: iterator it;
        for(it = adjlist[i].begin();it!=adjlist[i].end();it++){
            cout<<*it<<" ";
        }cout<<"\n";
        // for(int x: mat2D[i]){
        //     cout<<x<<" ";
        // }cout<<"\n";
    }
}