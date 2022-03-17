//
// Created by abhi on 27/09/21.
//
#include <iostream>
using namespace std;


class node{
public:
    int val;
   node* next;

   node(int value){
       val=value;
       next=nullptr;
   }

};

class queue{
   node* front;
   node* back;
public:
    queue(){
        front= nullptr;
        back= nullptr;
    }

   void push(int val){
        node* temp = new node(val);
       if(back != nullptr){
           back->next=temp;
           back= temp;
       }
        if(back== nullptr ) {
            back=temp;
        }
        if(front== nullptr){
            front=temp;
        }

    }
    int peek(){
        if(front == nullptr)return  -1;
        return front->val;
    }
    void pop(){
        if(front->val==back->val){
            node* todelete = front;
            front= nullptr;
            back= nullptr;
            delete todelete;
            return;
        }
        node* todelete = front;
        front=front->next;
        delete todelete;
    }
    bool empty(){
        if( front== nullptr)return false;
        return true;
    }
};

int main(){
    queue st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<st.peek();
    st.pop();
    cout<<st.peek();
    st.pop();
    cout<<st.peek();
    st.pop();
    cout<<endl<<st.empty();

    cout<<st.peek();
    st.pop();
    cout<<st.peek();
    st.pop();
    cout<<endl<<st.empty();
    return 0;
}