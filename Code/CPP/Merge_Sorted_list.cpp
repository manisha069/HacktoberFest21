#include <iostream>
using namespace std;

class node{

  public:
  int data;
  node* next;

  node(int data){
    this->data = data;
    next = NULL;
  }
};

void insertathead(node* &head,int data){
  if(head == NULL){
    head = new node(data);
    return;
  }

  node* n = new node(data);
  n->next = head;
  head = n;
}

void print(node * head){
  while(head!=NULL){
    cout<<head->data<<"-->";
    head = head->next;
  }
  cout<<endl;
}

node* merge(node* a, node* b){

  if(a==NULL){
    return b;
  }
  if(b==NULL){
    return a;
  }

  node* c;

  if(a->data < b->data){
    c=a;
    c->next = merge(a->next,b);
  }else{
    c=b;
    c->next = merge(a,b->next);
  }
  return c;
}


int main(){

  node* a = NULL;
  insertathead(a,10);
  insertathead(a,7);
  insertathead(a,5);
  insertathead(a,1);

   node* b = NULL;
  insertathead(b,6);
  insertathead(b,3);
  insertathead(b,2);

  node* head = merge(a,b);

  print(head);
  return 0;
}