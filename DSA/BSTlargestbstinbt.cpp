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
struct infoOfNode{
    int size,max,min,ans;
    bool isbst;
};
infoOfNode largestbstinbt(node *root){
    if(root == NULL){
        return {0,INT_MIN,INT_MAX,0,true};
    }
    if(root->left == NULL && root->right == NULL){
        return {1,root->data,root->data,1,true};
    }
    infoOfNode leftinfo = largestbstinbt(root->left);
    infoOfNode rightinfo = largestbstinbt(root->right);
    infoOfNode curr;
    curr.size = (1+leftinfo.size + rightinfo.size);
    if(leftinfo.isbst && rightinfo.isbst && leftinfo.max < root->data && rightinfo.min > root->data){
        curr.min = min(leftinfo.min ,min(rightinfo.min , root->data));
        curr.max = max(leftinfo.max,max(rightinfo.max, root->data));
        curr.ans = curr.size;
        curr.isbst = true;
        return curr;
    }
    curr.ans = max(leftinfo.ans,rightinfo.ans);
    curr.isbst = false;
    return curr;
}
int main(){
    node *root = new node(5);
    root->left = new node(1);
    root->right = new node(7);
    root->left->right = new node(3);
    root->left->right->right = new node(4);
    root->left->right->left = new node(2);
    cout<<"Largest BST Size is: "<<largestbstinbt(root).ans<<"\n";
}
