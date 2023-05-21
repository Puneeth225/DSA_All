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
vector<node*> nooftrees(int start,int end){
    vector<node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start;i<=end;i++){
        vector<node*> subtreeonleft = nooftrees(start,i-1);
        vector<node*> subtreeonright = nooftrees(i+1,end);
        for(int j=0;j<subtreeonleft.size();j++){
            node *maintreekaleft = subtreeonleft[j];
            for(int k=0;k<subtreeonright.size();k++){
                node *maintreekaright = subtreeonright[k];
                node *root = new node(i);
                root->left = maintreekaleft;
                root->right = maintreekaright;
                trees.push_back(root);
            }
        }
    }
    return trees;
}
void preorder(node *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    vector<node*> totaltreesforn = nooftrees(3,5);
    for(int i=0;i<totaltreesforn.size();i++){
        cout<<i+1<<": ";
        preorder(totaltreesforn[i]);
        cout<<"\n";
    }
}