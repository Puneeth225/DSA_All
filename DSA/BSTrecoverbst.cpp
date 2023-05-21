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
void interchange(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void calcpointers(node *root,node **first,node **mid,node **last,node **prev){
    if(root == NULL){
        return;
    }
    calcpointers(root->left,first,mid,last,prev);
    if(*prev && root->data < (*prev)->data){
        if(!*first){
            *first = *prev;
            *mid = root;
        }
        else{
            *last = root;
        }
    }
    *prev = root;
    calcpointers(root->right,first,mid,last,prev);
}
void restorebst(node *root){
    node *first, *mid, *last, *prev;
    first = NULL;
    mid = NULL;
    last = NULL;
    prev = NULL;
    calcpointers(root, &first, &mid, &last, &prev);
    if(first && last){
        interchange(&(first->data),&(last->data));
    }
    else if(first && mid){
        interchange(&(first->data),&(mid->data));
    }
}
void inorder(node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    node *root = new node(5);
    root->left = new node(1);
    root->right = new node(7);
    root->left->right = new node(4);
    root->left->right->right = new node(3);
    root->left->right->left = new node(2);
    inorder(root);
    cout<<"\n";
    restorebst(root);
    inorder(root);
    cout<<"\n";
}