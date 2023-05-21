//to find minimum distance between two vertices u and v
#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main(){
    vector<vector<int>>graph = {{0,5,INF,10},{INF,0,3,INF},{INF,INF,0,1},{INF,INF,INF,0}};
    int n = graph.size();
    vector<vector<int>>dist = graph;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(dist[j][i]+dist[i][k] < dist[j][k]){
                    dist[j][k] = dist[j][i]+dist[i][k];
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dist[i][j] == INF){
                cout<<"INF";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<"\n";
    }
}