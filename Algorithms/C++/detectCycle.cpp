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

void insertAtTail(node* &head, int val){
    node* newnode = new node(val);
    node* temp = head;
    
    if(head==NULL){
        head = newnode;
        return;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

void display(node* head){
    node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;

        if( fast == slow){
            return true;
        }
    }
    return false;
};

void makeCycle(node* &head, int pos){
    node* temp = head;
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

void removeCycle(node* head){
    node* slow = head;
    node* fast = head;

    do{
        fast = fast->next->next;
        slow = slow->next;
    }
    while(slow!=fast);

    fast = head;
    while(fast->next!=slow->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
};

int main(){

    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    // display(head);
    makeCycle(head,3);
    cout<<detectCycle(head)<<endl;
    removeCycle(head);
    cout<<detectCycle(head)<<endl;
    // display(head);
    
    return 0;
}