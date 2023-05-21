//              5
//             / \
//            1   7
//             \
//              3
//             / \
//            2   4
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *left, *right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
bool checkifbst(node *root, node *mn=NULL,node *mx=NULL){
    if(root == NULL){
        return true;
    }
    if(mn!=NULL && root->data<=mn->data){
        return false;
    }
    if(mx!=NULL && root->data>=mx->data){
        return false;
    }
    bool leftcheck = checkifbst(root->left,mn,root);
    bool rightcheck = checkifbst(root->right,root,mx);
    return leftcheck and rightcheck;
}
int main(){
    node *root = new node(5);
    root->left = new node(1);
    root->right = new node(7);
    root->left->right = new node(3);
    root->left->right->right = new node(4);
    root->left->right->left = new node(2);
    if(checkifbst(root,NULL,NULL)){
        cout<<"Yes, it is BST"<<"\n";
    }
    else{
        cout<<"Not a BST"<<"\n";
    }
}