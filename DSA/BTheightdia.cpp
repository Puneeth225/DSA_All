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
int heightoftree(node *root){      //o(n) is time complexity
    if(root == NULL){
        return 0;
    }
    int leftHight = heightoftree(root->left);
    int rightHight = heightoftree(root->right);
    return max(leftHight,rightHight)+1;
}
int diameteroftree(node *root){    //o(n^2)
    if(root == NULL){
        return 0;
    }
    int lheight =  heightoftree(root->left);
    int rheight = heightoftree(root->right);
    int currentdia = lheight+rheight+1;
    int leftdia = diameteroftree(root->left);
    int rightdia = diameteroftree(root->right);
    return max(currentdia,max(leftdia,rightdia));
}
//optimized diameter solution
/*int diameteroptimized(node *root,int *height){       //o(n)
    if(root == NULL){
        *height = 0;
        return 0;
    }
    int lh = 0,rh = 0;
    int ldia = diameteroptimized(root->left,&lh);
    int rdia = diameteroptimized(root->right, &rh);
    int currdia = lh+rh+1;
    *height = max(lh,rh)+1;
    return max(currdia,max(ldia,rdia));
}*/
int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<heightoftree(root)<<"\n";
    cout<<diameteroftree(root)<<"\n";
    //int height =0;
    //cout<<diameteroptimized(root,&height)<<"\n";
}