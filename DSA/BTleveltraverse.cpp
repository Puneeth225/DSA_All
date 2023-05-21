#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
void leveltraverse(node *root){
    if(root == NULL){
        return;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* newroot = q.front();
        q.pop();
        if(newroot!=NULL){
            cout<<newroot->data<<" ";
            if(newroot->left){
            q.push(newroot->left);
            }
            if(newroot->right){
                q.push(newroot->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
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
    leveltraverse(root);
}