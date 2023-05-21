//              30
//             / \
//            10  40
//             \   \
//              20  50
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
node *bstfromsortedarr(int arr[],int start, int end){
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2;
    node *root = new node(arr[mid]);
    root->left = bstfromsortedarr(arr,start,mid-1);
    root->right = bstfromsortedarr(arr,mid+1,end);
    return root;
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
    int arr[] = {10,20,30,40,50};
    node *gotbst = bstfromsortedarr(arr,0,4);
    preorder(gotbst);
}