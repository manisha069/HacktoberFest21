#include <bits/stdc++.h>
using namespace std;

//Implementation of min stack in O(1) Space and Time complexity

/*let y be newMinimum and x be oldMinimum
=> y<x
=> 2y<x+y
=> 2y-x<y So, we use 2y-x as flag here */


struct MyStack
{
stack<int>s;
int minElement;

//to get minimum element of stack
void getMin()
{
    if(s.size()==0)
    cout<< -1<<endl;
    else
    cout<<minElement<<endl;;
}


void push(int x)
{
    if(s.size()==0)
    {
        s.push(x);
        minElement=x; //for empty stack, only element will be the minElement
    }
    else {
    if(x>=minElement)
    {
        s.push(x); //greater element is pushed directly, no updates to minElement
    }
    else
    {
        s.push(2*x-minElement); //used as a flag since it will be lower than minElement
        minElement=x; //new minElement updated
    }
    }
}

void pop()
{
    if(s.size()==0)
    cout<< -1<<endl;

    else{
        if(s.top()>=minElement)
        s.pop(); //greater element popped since its not minimum
        else{
            //working as flag
            minElement=2*minElement-s.top(); //flag indicated we had updated minElement, so getting previous minElement
            s.pop();
        }
    }
}

void top()
{
    if(s.size()==0)
    cout<< -1<<endl;
    else{
        if(s.top()>=minElement)
        cout<< s.top()<<endl; //element at top
        else
        cout<< minElement<<endl; //element in stack is actually flag, real element is in minElement 
    }
}
};
int main()
{
    MyStack s;
    s.push(3);
    s.push(5);
    s.getMin();
    s.push(2);
    s.push(1);
    s.getMin();
    s.pop();
    s.getMin();
    s.pop();
    s.top();
    return 0;
}
