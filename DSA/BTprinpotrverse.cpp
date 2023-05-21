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
//with recursion
void preorder(struct node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(struct node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//without recursion
/*void preorder(node *root) {
    if (root == NULL) return;
    stack <node *> s;
    s.push(root);
    while (!s.empty()) {
        node *temp = s.top();
        cout << temp -> data <<" ";
        s.pop();
        if (temp -> right != NULL) s.push(temp -> right);
        if (temp -> left != NULL) s.push(temp -> left);
    }
}

void postorder(node *root) {
    if (root == NULL) return;
    stack <node *> s1,s2;
    node * temp = root;
    s1.push(temp);
    while (!s1.empty()) {
        temp = s1.top();
        s1.pop();
        s2.push(temp);
        if (temp -> left != NULL) s1.push(temp -> left);
        if (temp -> right != NULL) s1.push(temp -> right);
    }
    while(!s2.empty()) {
        cout << s2.top() -> data <<" ";
        s2.pop();
    }
    cout << endl;
}
void inorder(node *root) {
    if (root == NULL) return;
    stack  s;
    node * temp = root;
    while (!s.empty() || temp != NULL) {
        while (temp != NULL) {
            s.push(temp);
            temp = temp -> left;
        }
        temp = s.top();
        cout << temp -> data <<" ";
        s.pop();
        temp = temp -> right;
    }
}*/
int main(){
    struct node *root = new node(1);                                /*             1                    */
    root->left = new node(2);                                       /*            / \                   */
    root->right = new node(3);                                      /*           2   3                  */
    root->left->left = new node(4);                                 /*          / \ / \                 */
    root->left->right = new node(5);                                /*         4  5 6  7                */
    root->right->left = new node(6);
    root->right->right = new node(7);
    preorder(root);
    cout<<"\n";
    inorder(root);
    cout<<"\n";
    postorder(root);

}
