#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node *prev;
    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
int lengthofLL(node*&head){
    int l = 0;
    node*temp = head;
    while(temp!=NULL){
        temp = temp->next;
        l++;
    }
    return l;
}
int intersection(node*&head1,node*&head2){
    int l1 = lengthofLL(head1);
    int l2 = lengthofLL(head2);
    int d=0;
    node*p1;
    node*p2;
    if(l1>l2){
        d = l1-l2;
        p1 = head1;
        p2 = head2;
    }
    else{
        d = l2-l1;
        p1 = head2;
        p2 = head1;
    }
    while(d){
        p1 = p1->next;
        if (p1 == NULL)
        {
            return -1;
        }
        d--;
    }
    while(p1!=NULL && p2!=NULL){
        if(p1==p2){
            return p1->data;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return -1;
}
void insertathead(node*&head,int val){
    node *n = new node(val);
    n->next = head;
    if(head!=NULL){
        head->prev = n;
    }
    head = n;
}
void insertattail(node*&head, int val){
    if(head==NULL){
        insertathead(head,val);
        return;
    }
    node *n = new node(val);
    node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
void display(node*&head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<"\n";
}
void intersect(node*&head1,node*&head2,int pos){
    node* temp1 = head1;
    pos--;
    while(pos--){
        temp1 = temp1->next;
    }
    node* temp2  = head2;
    while(temp2->next!=NULL){
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int main(){
    node* head1 = NULL;
    node* head2 = NULL;
    insertattail(head1,12);
    insertattail(head1,13);
    insertattail(head1,14);
    insertattail(head1,15);
    insertattail(head1,16);
    insertattail(head2,26);
    insertattail(head2,27);
    intersect(head1,head2,3);
    display(head1);
    display(head2);
    cout<<intersection(head1,head2);
     
    
}