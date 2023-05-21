//There is a 2D grid of 'X' and 'O' and convert all 'O' to 'X' which are surrounded by 'X' 
// X X X X             X X X X  
// X O O X   ---->     X X X X
// X X O X             X X X X
// X O X X             X O X X
#include<bits/stdc++.h>
using namespace std;
void change(vector<vector<char>>&grid, int x, int y){
    grid[x][y] = '*';
    int dx[] = {0,0,-1,1};
    int dy[] = {1,-1,0,0};
    for(int i=0;i<4;i++){
        int x_coord = x+dx[i];
        int y_coord = y+dy[i];
        if(x_coord>=0 && x_coord<grid.size() && y_coord>=0 && y_coord<grid[0].size() && grid[x_coord][y_coord] =='O'){
            change(grid,x_coord,y_coord);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==n-1 || j==0 || j==m-1){
                if(grid[i][j] == 'O'){
                    change(grid,i,j); // change 'O' to * from boundaries which are not surrounded
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'O'){
                grid[i][j] = 'X';
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '*'){
                grid[i][j] = 'O';
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
}
