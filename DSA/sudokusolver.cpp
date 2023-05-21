// given an filled sudoku grid fill the correct numbers at '.' places
/*#include <bits/stdc++.h>
using namespace std;
void helper(int r, int c, vector<vector<char>> &a, map<pair<int,int>,map<int,int>> &mp,vector<map<int,int>> row, vector<map<int,int>>column){
    if(r==9){
        for(auto it:a){
            for(auto i:it){
                cout<<i<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }
    if(c ==9){
        helper(r,c+1,a,mp,row,column);
        return;
    }
    if(a[r][c]!='.'){
        helper(r,c+1,a,mp,row,column);
        return;
    }
    for(int i=1;i<=9;i++){
        int grid33row = r/3;
        int grid33column = c/3;
        if(!mp[{grid33row,grid33column}][i] && !row[r][i] && !column[c][i]){
            mp[{grid33row,grid33column}][i] = 1;
            row[r][i] = 1;
            column[c][i] = 1;
            a[r][c] = i+'0';
            helper(r,c+1,a,mp,row,column);
            mp[{grid33row,grid33column}][i] = 0;
            row[r][i] = 0;
            column[c][i] = 0;
            a[r][c] = '.';
        }
    }

}
void solvesudoku(vector<vector<char>> &a){
    map<pair<int,int>,map<int,int>>mp;
    vector<map<int,int>>row(9);
    vector<map<int,int>> column(9);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(a[i][j] != '.'){
                mp[{i/3,j/3}][a[i][j]-'0'] = 1;
                row[i][a[i][j]-'0'] = 1;
                column[j][a[i][j]-'0'] = 1;
            }
        }
    }
    helper(0,0,a,mp,row,column);
}
int main(){
    vector<vector<char>> s1;
    s1 = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    solvesudoku(s1);
}*/




#include<bits/stdc++.h>
using namespace std;
#define n 9
bool issafe(int sgrid[n][n],int row,int col, int num){
    for(int i=0;i<n;i++){     // check if same number is in the same row
        if(sgrid[row][i] == num){
            return false;
        }
    }
    for(int i=0;i<n;i++){         // check if same number is in the same column
        if(sgrid[i][col] == num){
            return false;
        }
    }
    int grid33r = row - row%3;
    int grid33c = col - col%3;
    for(int i=0;i<3;i++){      //checks if number is present in same 3X3 grid
        for(int j=0;j<3;j++){
            if(sgrid[i+grid33r][j+grid33c] == num){
                return false;
            }
        }
    }
    return true;
}
bool solvesudoku(int sgrid[n][n],int row,int col){
    if(row == n-1 && col == n){
        return true;
    }
    if(col == n){
        row++;
        col = 0;
    }
    if(sgrid[row][col]>0){
        return solvesudoku(sgrid,row,col+1);
    }
    for(int num = 1;num<=n;num++){
        if(issafe(sgrid,row,col,num)){
            sgrid[row][col] = num;
            if(solvesudoku(sgrid,row,col+1)){
                return true;
            }
        }
        sgrid[row][col] = 0;
    }
    return false;
}
int main(){
    int s[n][n] = {
        {3,0,6,5,0,8,4,0,0},
        {5,2,0,0,0,0,0,0,0},
        {0,8,7,0,0,0,0,3,1},
        {0,0,3,0,1,0,0,8,0},
        {9,0,0,8,6,3,0,0,5},
        {0,5,0,0,9,0,6,0,0},
        {1,3,0,0,0,0,2,5,0},
        {0,0,0,0,0,0,0,7,4},
        {0,0,5,2,0,6,3,0,0}
    };
    if(solvesudoku(s,0,0)){
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<s[i][j]<<" ";
        }
        cout<<"\n";
    }
    }
    else{
        cout<<"Wrong grid given"<<"\n";
    }
}
