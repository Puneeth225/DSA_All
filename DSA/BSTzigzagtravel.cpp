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
void zigzagtraverse(node *root){
    if(root == NULL){
        return;
    }
    stack<node*> currlevel;
    stack<node*> nxtlevel;
    bool rightTOleft = true;
    currlevel.push(root);
    while(!currlevel.empty()){
        node *temp = currlevel.top();
        currlevel.pop();
        if(temp){
            cout<<temp->data<<" ";
        if(rightTOleft){
            if(temp->left){
                nxtlevel.push(temp->left);
            }
            if(temp->right){
                nxtlevel.push(temp->right);
            }
        }
        else{
            if(temp->right){
                nxtlevel.push(temp->right);
            }
            if(temp->left){
                nxtlevel.push(temp->left);
            }
        }
        }
        if(currlevel.empty()){
            rightTOleft = !rightTOleft;
            swap(currlevel,nxtlevel);
        }
    }
}
int main(){
    node *root = new node(5);
    root->left = new node(1);
    root->right = new node(7);
    root->left->right = new node(3);
    root->left->right->right = new node(4);
    root->left->right->left = new node(2);
    zigzagtraverse(root);
    
}