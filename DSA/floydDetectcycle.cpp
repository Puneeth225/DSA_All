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

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}

void makecycle(node*&head, int pos){
    node *temp = head;
    node* startnode;
    int count = 1;
    while(temp->next!=NULL){
        if(count == pos){
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
}

bool findcycle(node* &head){
    node *slow = head;
    node *fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}

void removecycle(node* &head){
    node* slow = head;
    node* fast = head;
    do
    {
        slow = slow->next;
        fast= fast->next->next;
    } while (slow!=fast);
    fast = head;
    while(slow->next!=fast->next){
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}
int main(){
    node* head = NULL;
    insertattail(head,95);
    insertattail(head,96);
    insertattail(head,97);
    insertattail(head,98);
    display(head);
    makecycle(head,2);
    //display(head);
    cout<<findcycle(head)<<"\n";
    removecycle(head);
    cout<<findcycle(head)<<"\n";
    display(head);

}