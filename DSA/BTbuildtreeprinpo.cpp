#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};
int findpos(int inoder[],int start,int end,int current){
    for(int i=start;i<=end;i++){
        if(inoder[i]==current){
            return i;
        }
    }
    return -1;
}
node *buildtree(int preoder[],int inoder[],int start,int end){
    static int index = 0;
    if(start>end){
        return NULL;
    }
    int current = preoder[index];
    index++;
    node *newnode = new node(current);
    if(start == end){
        return newnode;
    }
    int pos = findpos(inoder,start,end,current);
    newnode->left = buildtree(preoder,inoder,start,pos-1);
    newnode->right = buildtree(preoder,inoder,pos+1,end);
    return newnode;
}
void inoderprint(node *root){
    if(root == NULL ){
        return;
    }
    inoderprint(root->left);
    cout<<root->data<<" ";
    inoderprint(root->right);
}
int main(){
    int preoder[] = {1,2,4,3,5};                                         
    /*             1                    */
    /*            / \                   */
    /*           2   3                  */
    /*          /   /                   */
    /*         4   5                    */
    int inoder[] = {4,2,1,5,3};
    inoderprint(buildtree(preoder,inoder,0,4));
    //cout<<buildtree(preoder,inoder,0,4);
}