/*           1          l=0           */
/*          /  \                      */
/*         2    3       l=1           */
/*        / \  / \                    */
/*       4   5 6  7     l=2           */
#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
int countnodes(node* root){
    if(root == NULL){
        return 0;
    }
    return countnodes(root->left)+countnodes(root->right)+1;
}
int sumofnodes(node *root){
    if(root == NULL){
        return 0;
    }
    return sumofnodes(root->left) + sumofnodes(root->right) + root->data;
}
int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<countnodes(root)<<"\n";
    cout<<sumofnodes(root)<<"\n";
}