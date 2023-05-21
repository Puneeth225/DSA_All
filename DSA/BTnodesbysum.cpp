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
void nodebysum(node *root){
    if(root == NULL){
        return;
    }
    nodebysum(root->left);
    nodebysum(root->right);
    if(root->left!=NULL){
        root->data += root->left->data;
    }
    if(root->right!=NULL){
        root->data += root->right->data;
    }
}
void preorder(node *root){    //to check new binary tree replaced by nodes with sum of sub-trees nodes
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    preorder(root);
    cout<<"\n";
    nodebysum(root);
    preorder(root);
    cout<<"\n";
}