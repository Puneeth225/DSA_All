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
node *insertioninbst(node *root,int value){
    if(root == NULL){
        return new node(value);
    }
    if(value<root->data){
        root->left = insertioninbst(root->left,value);
    }
    else{
        root->right = insertioninbst(root->right,value);
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
    node *root = NULL;
    root = insertioninbst(root,5);
    insertioninbst(root,1);
    insertioninbst(root,3);
    insertioninbst(root,4);
    insertioninbst(root,2);
    insertioninbst(root,7);
    inoreder(root);
    cout<<"\n";

}


