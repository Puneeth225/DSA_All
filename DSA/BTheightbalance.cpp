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
int height(node  *root){
    if(root == NULL){
        return 0;
    }
    int lfthigt = height(root->left);
    int rigthgt = height(root->right);
    return max(lfthigt,rigthgt)+1;
}
bool isbalanced(node *root){            //o(n^2)
    if(root == NULL){
        return true;
    }
    if(isbalanced(root->left)==false){
        return false;
    }
    if(isbalanced(root->right)==false){
        return false;
    }
    int lfthight = height(root->left);
    int rigthight = height(root->right);
    if(abs(lfthight-rigthight)<=1){
        return true;
    }
    else{
        return false;
    }
}
/*bool isbalancedoptimized(node *root,int *h){      //o(n)
    if(root == NULL){
        return true;
    }
    int lh = 0,rh = 0;
    if(isbalancedoptimized(root->left,&lh)==false){
        return false;
    }
    if(isbalancedoptimized(root->right,&rh)==false){
        return false;
    }
    *h = max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}*/
int main(){
    node *roottree = new node(1);
    roottree->left = new node(2);
    roottree->right = new node(3);
    roottree->left->left = new node(4);
    roottree->left->right = new node(5);
    roottree->right->left = new node(6);
    roottree->right->right = new node(7);
    if(isbalanced(roottree)){
        cout<<"It is balanced"<<"\n";
    }
    else{
        cout<<"NOT balanced"<<"\n";
    }
    //int hgt = 0;
    //if(isbalancedoptimized(roottree,&hgt)==true){
        //cout<<"Balanced Tree"<<"\n";
    //}
    //else{
    //    cout<<"NOT Balanced"<<"\n";
    //}
}