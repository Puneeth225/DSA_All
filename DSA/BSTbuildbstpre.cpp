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
node *constructbstpre(int preorder[],int *preindx,int key,int mn,int mx,int n){
    if(*preindx >=n){
        return NULL;
    }
    node *root = NULL;
    if(key>mn &&key<mx){
        root = new node(key);
        *preindx = *preindx+1;
        if(*preindx<n){
            root->left = constructbstpre(preorder,preindx,preorder[*preindx],mn,key,n);
        }
        if(*preindx<n){
            root->right = constructbstpre(preorder,preindx,preorder[*preindx],key,mx,n);
        }
    }
    return root;
}
void printpreoder(node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    printpreoder(root->left);
    printpreoder(root->right);
}
int  main(){                   //o(n)
    //         10
    //        /  \
    //       2    13
    //      /     /
    //     1     11
    int preorder[] = {10,2,1,13,11};
    int n = 5;
    int preindx = 0;
    node *ans = constructbstpre(preorder,&preindx,preorder[0],INT_MIN,INT_MAX,n);
    printpreoder(ans);
}