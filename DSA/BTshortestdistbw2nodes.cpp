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
node *leastcomonancestor(node *root,int n1,int n2){
    if(root == NULL){
        return NULL;
    }
    if(root->data == n1||root->data == n2){
        return root;
    }
    node *left = leastcomonancestor(root->left,n1,n2);
    node *right = leastcomonancestor(root->right,n1,n2);
    if(left!=NULL&&right!=NULL){
        return root;
    }
    if(left==NULL&&right==NULL){
        return NULL;
    }
    if(left!=NULL){
        return leastcomonancestor(root->left,n1,n2);
    }
    return leastcomonancestor(root->right,n1,n2);
}
int disttolca(node *root,int todist,int d){
    if(root == NULL){
        return -1;
    }
    if(root->data == todist){
        return d;
    }
    int left = disttolca(root->left,todist,d+1);
    if(left != -1){
        return left;
    }
    return disttolca(root->right,todist,d+1);
}
int findDisttotal(node *root,int n1,int n2){
    node *lca = leastcomonancestor(root,n1,n2);
    int lftdist = disttolca(lca,n1,0);
    int rgtdist = disttolca(lca,n2,0);
    return lftdist + rgtdist;
}
int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<findDisttotal(root,4,7)<<"\n";
}