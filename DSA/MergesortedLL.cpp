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
node* merge(node* head1,node *head2){
    node* p1 = head1;
    node *p2 = head2;
    node *dummynode = new node(-1);
    node *p3 = dummynode;
    while(p1!=NULL&&p2!=NULL){
        if(p1->next<p2->next){
            p3->next = p1;
            p1 = p1->next;
        }
        else{
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }
    while(p1!=NULL){
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while(p2!=NULL){
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummynode->next;
}
node* mergerecurse(node*head1,node*head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    node *res;
    if(head1->data<head2->data){
        res = head1;
        res->next = mergerecurse(head1->next,head2);
    }
    else{
        res = head2;
        res->next = mergerecurse(head1,head2->next);
    }
    return res;
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
int main(){
    node *head1 = NULL;
    node *head2 = NULL;
    int LL1[] = {10,20,30,40,50};
    int LL2[] = {60,70,80,90,100};
    for(int i= 0;i<5;i++){
        insertattail(head1,LL1[i]);
    }
    for(int i= 0;i<5;i++){
        insertattail(head2,LL2[i]);
    }
    display(head1);
    display(head2);
    //node *ans = merge(head1,head2);
    node *ans = mergerecurse(head1,head2);
    display(ans);
}