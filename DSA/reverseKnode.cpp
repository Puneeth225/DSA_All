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
node* reverseK(node* &head, int k){
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;
    int count = 0;
    while(currptr!=NULL && count<k){
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr= currptr;
        currptr = nextptr;
        count++;
    }
    if(nextptr!=NULL){
        head->next = reverseK(nextptr,k);
    }
    return prevptr;
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
    insertattail(head,95);
    insertattail(head,96);
    insertattail(head,97);
    insertattail(head,98);
    insertattail(head,99);
    insertattail(head,100);
    display(head);
    int k = 3;
    node* ans = reverseK(head,k);
    display(ans);

}