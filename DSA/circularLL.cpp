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
void insertathead(node* &head, int val){
    node *n = new node(val);
    if(head==NULL){
        n->next = n;
        head = n;
        return;
    }
    node *temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;

}
void insertattail(node* &head,int val){
    if(head==NULL){
        insertathead(head,val);
            return;
    }
    node* n= new node(val);
    node *temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}
void deleteathead(node* &head){
    node* temp  = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    node *bedel = head;
    temp->next = head->next;
    head = head->next;
    delete bedel;
}
void deletion(node* &head,int pos){
    if(pos==1){
        deleteathead(head);
        return;
    }
    node *temp = head;
    int cnt = 1;
    while(cnt!=pos-1){
        temp = temp->next;
        cnt++;
    }
    node *bedel = temp->next;
    temp->next = temp->next->next;
    delete bedel;
}
void display(node*head){
    node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp!=head);
    cout<<"\n";
}
int main(){
    node *head = NULL;
    insertattail(head,45);
    insertattail(head,41);
    insertattail(head,10);
    insertattail(head,22);
    insertattail(head,656);
    display(head);
    insertathead(head,100);
    display(head);
    deletion(head,4);
    display(head);
}