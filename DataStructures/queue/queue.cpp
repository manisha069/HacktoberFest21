//
// Created by abhi on 27/09/21.
//

#include<iostream>
using namespace std;
int n=10;
class queue{
    int n=100;
    int* arr;
    int front;
    int back;
public:
    queue(){
        arr= new int[100];
        front=-1;
        back=-1;
    }

    void push(int val){
        if(back>n){
            cout<<" queue overflowed";
            return;
        }
        back++;
        arr[back]=val;
        if(front==-1)front++;
    }
    int peek(){
        if(front==-1 || front>back){
            return -1;
        }
        return arr[front];
    }
    void pop(){
        if(front!=-1 && front<back){
            front++;
        }
    }
    bool empty(){
        if(front!=-1 && front<back)return false;
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