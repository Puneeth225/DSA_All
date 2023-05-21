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
bool getpath(node *root,int key,vector<int> &p){
    if(root == NULL){
        return false;
    }
    p.push_back(root->data);
    if(root->data == key){
        return true;
    }
    if(getpath(root->left,key,p)||getpath(root->right,key,p)){
        return true;
    }
    p.pop_back();
    return false;
}
int lca(node *root,int n1,int n2){            //o(n)
    vector<int> p1,p2;
    if(!getpath(root,n1,p1) || !getpath(root,n2,p2)){
        return -1;
    }
    int pathchng;
    for(pathchng =0;pathchng<p1.size()&&p2.size();pathchng++){
        if(p1[pathchng]!=p2[pathchng]){
            break;
        }
    }
    return p1[pathchng-1];
}
/*node *llca(node *root,int n1,int n2){     //one tree traversal o(n)
    if(root == NULL){
        return NULL;
    }
    if(root->data ==n1||root->data == n2){
        return root;
    }
    node *leftsidelca = llca(root->left,n1,n2);
    node *rightsidelca = llca(root->right,n1,n2);
    if(leftsidelca && rightsidelca){
        return root;
    }
    if(leftsidelca !=NULL){
        return leftsidelca;
    }
    return rightsidelca;
}*/
int main(){
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    int ans = lca(root,7,6);
    if(ans == -1){
        cout<<"LCA do not exist."<<"\n";
    }
    else{
        cout<<"LCA : "<<ans<<"\n";
    }
    /*node *ans1 = llca(root,7,6);
    if(ans1 == NULL){
        cout<<"LCA do not exist."<<"\n";
    }
    else{
        cout<<"LCA : "<<ans1->data<<"\n";
    }*/
}
