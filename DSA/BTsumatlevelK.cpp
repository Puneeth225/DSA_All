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
int sumatK(node *root,int k){
    if(root == NULL){
        return -1;
    }
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    int level =0,sum = 0;
    while(!q.empty()){
        node *newroot = q.front();
        q.pop();
        if(newroot!=NULL){
            if(level == k){
                sum+=newroot->data;
            }
            if(newroot->left){
                q.push(newroot->left);
            }
            if(newroot->right){
                q.push(newroot->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}
int main(){
    node *root = new node(1);                           /*           1          l=0           */
    root->left = new node(2);                           /*          /  \                      */
    root->right = new node(3);                          /*         2    3       l=1           */
    root->left->left = new node(4);                     /*        / \  / \                    */
    root->left->right = new node(5);                    /*       4   5 6  7     l=2           */
    root->right->left = new node(6);
    root->right->right = new node(7);
    //leveltraverse(root);
    cout<<sumatK(root,2);
}