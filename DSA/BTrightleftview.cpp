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
//Tree when seen from right, only right elements of tree are printed
void viewfromright(node *root){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            node *curr = q.front();
            q.pop();
            if(i==n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}
//Tree when seen from left, only left elements of tree are printed
void viewfromleft(node *root){
    if(root == NULL){
        return;
    }
    queue<node*> q1;
    q1.push(root);
    while(!q1.empty()){
        int n = q1.size();
        for(int i=1;i<=n;i++){
            node *temp = q1.front();
            q1.pop();
            if(i==1){
                cout<<temp->data<<" ";
            }
            if(temp->left!=NULL){
                q1.push(temp->left);
            }
            if(temp->right!=NULL){
                q1.push(temp->right);
            }
        }
    }
}
int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    viewfromright(root);
    cout<<"\n";
    viewfromleft(root);
}