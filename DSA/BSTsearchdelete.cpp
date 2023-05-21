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
node *searchinbst(node *root,int key){
    if(root == NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(key<root->data){
        return searchinbst(root->left,key);
    }
    return searchinbst(root->right,key);
}
node *inordersuccessor(node *root){
    node *curr = root;
    while(curr && curr->left!=NULL){
        curr = curr->left;
    }
    return curr;
}
node *deleteinbst(node *root,int todel){
    if(todel<root->data){
        root->left = deleteinbst(root->left,todel);
    }
    else if(todel>root->data){
        root->right = deleteinbst(root->right,todel);
    }
    else{
        if(root->left == NULL){
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            node *temp = root->left;
            free(root);
            return temp;
        }
        node *temp = inordersuccessor(root->right);
        root->data = temp->data;
        root->right = deleteinbst(root->right,temp->data);
    }
    return root;
}
void inoreder(node *root){
    if(root == NULL){
        return;
    }
    inoreder(root->left);
    cout<<root->data<<" ";
    inoreder(root->right);
}
int main(){
    node *root = new node(5);
    root->left = new node(1);
    root->right = new node(7);
    root->left->right = new node(3);
    root->left->right->right = new node(4);
    root->left->right->left = new node(2);
    if(searchinbst(root,4)==NULL){
        cout<<"Value is not there"<<"\n";
    }
    else{
        cout<<"Value Exists"<<"\n";
    }
    inoreder(root);
    cout<<"\n";
    deleteinbst(root,3);
    inoreder(root);
}