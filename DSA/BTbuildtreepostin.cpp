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
node *buildtree(int postoder[],int inoder[],int start,int end){
    static int index = end;
    if(start>end){
        return NULL;
    }
    int current = postoder[index];
    index--;
    node *newnode = new node(current);
    if(start == end){
        return newnode;
    }
    int pos = findpos(inoder,start,end,current);
    newnode->right = buildtree(postoder,inoder,pos+1,end);
    newnode->left = buildtree(postoder,inoder,start,pos-1);
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
    int postoder[] = {4,2,5,3,1};
    int inoder[] = {4,2,1,5,3};
    inoderprint(buildtree(postoder,inoder,0,4));

}
