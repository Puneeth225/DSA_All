//print vertical order of Binary tree
//              10
//             /  \
//            7    4
//           / \  / \
//          3  11 14 6  
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left, *right;
};
node *newnode(int val){
    node *root  = new node;
    root->data = val;
    root->left = root->right = NULL;
    return root;
}
void verticalorder(node *root, int horizd, map<int,vector<int>> &m){
    if(root == NULL){
        return;
    }
    m[horizd].push_back(root->data);
    verticalorder(root->left,horizd-1,m);
    verticalorder(root->right,horizd+1,m);
}
int main(){
    node *root = newnode(10);
    root->left = newnode(7);
    root->right = newnode(4);
    root->left->left = newnode(3);
    root->left->right = newnode(11);
    root->right->left = newnode(14);
    root->right->right = newnode(6);
    map<int,vector<int>>mp;
    int horizontal_dist=0;
    verticalorder(root,horizontal_dist,mp);
    map<int,vector<int>> :: iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        for(int i=0;i<(it->second).size();i++){
            cout<<(it->second)[i]<<" ";
        }
        
    }cout<<"\n";
}