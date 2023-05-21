/*           1          l=0           */
/*          /  \                      */
/*         2    3       l=1           */
/*        / \  / \                    */
/*       4   5 6  7     l=2           */
#include <bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left;
    node *right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
int maxofleftrgtselfboth(node *root,int &ans){
    if(root == NULL){
        return 0;
    }
    int lftsum = maxofleftrgtselfboth(root->left,ans);
    int rgtsum = maxofleftrgtselfboth(root->right,ans);
    int finalmax = max(max(root->data,root->data +lftsum+rgtsum),max(root->data+lftsum,root->data+rgtsum));
    ans = max(ans,finalmax);
    int sumwithonepath = max(root->data,max(root->data+lftsum,root->data+rgtsum));
    return sumwithonepath;
}
int maxpathsum(node *root){
    int ans = INT_MIN;
    maxofleftrgtselfboth(root,ans);     //checks max of node value leftsubtree sum and rightsubtree sum and both left right and node
    return ans;
}
int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<maxpathsum(root);
}
/*int findmaxpathsum(node *root,int &result){
    if(root == NULL){
        return 0;
    }
    int lft = findmaxpathsum(root->left,result);
    int rgt = findmaxpathsum(root->right,result);
    result = max(result,root->data);
    result = max(result,root->data+lft);
    result = max(result,root->data+rgt);
    result = max(result,root->data+lft+rgt);
    return max(root->data,root->data+max(lft,rgt));
}*/