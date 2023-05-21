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
void subtreenodeatk(node *root,int k){
    if(root == NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    subtreenodeatk(root->left,k-1);
    subtreenodeatk(root->right,k-1);
}
int totalnodesatk(node *root,node *target,int k){
    if(root == NULL){
        return -1;
    }
    if(root == target){
        subtreenodeatk(root,k);
        return 0;
    }
    int dl = totalnodesatk(root->left,target,k);
    if(dl != -1){
        if(dl+1 == k){
            cout<<root->data<<" ";
        }
        else{
            subtreenodeatk(root->right,k-dl-2);
        }
        return 1+dl;
    }
    
    int dr = totalnodesatk(root->right,target,k);
    if(dr != -1){
        if(dr+1 == k){
            cout<<root->data<<" ";
        }
        else{
            subtreenodeatk(root->left,k-dr-2);
        }
        return 1+dr;
    }
    return -1;
}
int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    totalnodesatk(root,root->left,3);
}
