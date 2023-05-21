#include<iostream>
using namespace std;
class node1{
    public:
    int data;
    node1* next;
    node1(int val){
        data = val;
        next = NULL;
    }
};
void insertattail(node1* &head,int val){
    
    node1* n = new node1(val);
    if(head==NULL){
        head = n;
        return;
    }
    node1* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next=n;
}
void insertathead(node1* &head, int val){
    node1* n = new node1(val);
    n->next  = head;
    head = n;
}
bool search(node1* head, int key){
    node1* temp = head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
            
        }
        temp = temp->next;
    }
    return false;
}
void deletionathead(node1 *&head){
    node1 *bedel = head;
    head = head->next;
    delete bedel;
}
void deletion(node1 *&head, int val){
    if(head==NULL){
        return;// No element in LL
    }
    if(head->next==NULL){
        deletionathead(head);
        return;
    }
    node1 *temp = head;
    while(temp->next->data!=val){
        temp = temp->next;
    }
    node1 *bedel = temp->next;
    temp->next = temp->next->next;
    delete bedel;
}
void display(node1* head){
    node1* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}


int main(){
    node1* head = NULL;
    insertattail(head,1);
    insertattail(head,55);
    insertattail(head,6);
    insertattail(head,7);
    display(head);
    insertathead(head,4);
    display(head);
    cout<<search(head,5)<<"\n";
    deletion(head,55);
    display(head);
    deletionathead(head);
    display(head);


    return 0;
}
/*
node1* deleteNode(node1* head, int position) {
    if (position == 0){ return head->next; }
    head->next = deleteNode(head->next, position-1);
    
    return head;
}*/
