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

node* reverse(node*&head){
    node* prevpt = NULL;
    node *currpt = head;
    node* nextpt;
    while(currpt!=NULL){
        nextpt = currpt->next;
        currpt->next = prevpt;
        prevpt = currpt;
        currpt = nextpt;
    }
    return prevpt;
}
node* reversebyrecurse(node*&head){
    if((head ==NULL)||(head->next = NULL)){
        return head;
    }
    node* nayahead = reversebyrecurse(head->next);
    head->next->next = head;
    head->next = NULL;

    return nayahead;
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
    display(head);
    //node* aftrreverse = reverse(head);
    //display(aftrreverse);
    node* aftrreverse = reversebyrecurse(head);
    display(aftrreverse);

}