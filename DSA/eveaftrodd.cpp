#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data = val;
        next = NULL;
    }
};
void insertattail(node* &head,int val){
    
    node* n = new node(val);
    if(head==NULL){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=n;
}
void insertathead(node* &head, int val){
    node* n = new node(val);
    n->next  = head;
    head = n;
}
//function to place values at odd positions before even positions
void eveaftrodd(node* &head){
    node* odd = head;
    node* even = head->next;
    node* evenstart = even;
    while(odd->next!=NULL&& even->next!=NULL){
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenstart;
    if(odd->next!=NULL){
        even->next = NULL;
    }
}
void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}
int main(){
    node* head = NULL;
    insertattail(head,1);
    insertattail(head,9);
    insertattail(head,3);
    insertattail(head,4);
    insertattail(head,5);
    insertattail(head,7);
    display(head);
    eveaftrodd(head);
    display(head);
}