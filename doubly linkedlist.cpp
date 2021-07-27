#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int d;
    node* next;
    node* prev;
    node(int data){
        d = data;
        next = NULL;
        prev = NULL;
    }

};

void insertAtHead (node* &head,int val){
    node* n = new node(val);
    n->next = head;
    if (head != NULL)
    head->prev = n;
    head = n;
}
void insertAtTail(node* &head, int val){
    if (head == NULL){
        insertAtHead(head,val);
        return;
    }
    node* temp = head;
    node* n = new node(val);
    int count = 1;
    while (temp->next!= NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;


}
void deleteathead(node* &head){
    node *temp = head;
    head = head->next;

    head->prev=NULL;
    delete temp;
}
void deletion (node* &head, int pos){
    if (pos == 1){
        deleteathead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while (temp!=NULL and count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next!=NULL)
    temp->next->prev = temp->prev;
    delete temp;

}
void display(node* &head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->d<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    node* head = NULL;
    insertAtTail(head,8);
    insertAtTail(head,5);
    insertAtTail(head,3);
    insertAtTail(head,3);
    deletion(head,3);
    display(head);

    return 0;
}
