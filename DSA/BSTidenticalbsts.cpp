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
bool areidentical(node *root1,node *root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    else if(root1 == NULL|| root2 == NULL){
        return false;
    }
    else{
        bool checknodedata = root1->data == root2->data;
        bool checkleft = areidentical(root1->left,root2->left);
        bool checkright = areidentical(root1->right,root2->right);
        if(checknodedata && checkleft && checkright){
            return true;
        }
        return false;
    }
}
int main(){
    node *root = new node(5);
    root->left = new node(1);
    root->right = new node(7);
    root->left->right = new node(3);
    root->left->right->right = new node(4);
    root->left->right->left = new node(2);
    node *roottwo = new node(5);
    roottwo->left = new node(1);
    roottwo->right = new node(7);
    roottwo->left->right = new node(3);
    roottwo->left->right->right = new node(4);
    roottwo->left->right->left = new node(20);
    if(areidentical(root,roottwo)){
        cout<<"Identical Binary Search Trees"<<"\n";
    }
    else{
        cout<<"Not Identical BST's"<<"\n";
    }
}