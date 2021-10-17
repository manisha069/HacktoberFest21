#include<iostream>
using namespace std;
  
#define MAX 1000000 //size limit for stack
  
class Stack
{
   int top;
   public:
   int myStack[MAX]; //stack array
  
   Stack() { top = -1; }
   bool push(int x);
   int pop();
   bool isEmpty();
};
   //pushes element on to the stack
   bool Stack::push(int item)
   {
      if (top >= (MAX-1)) {
      cout << "Stack Overflow!!!";
      return false;
   }
else {
   myStack[++top] = item;
   cout<<item<<endl;
   return true;
   }
}
  
//removes or pops elements out of the stack
int Stack::pop()
{
   if (top < 0) {
      cout << "Stack Underflow!!";
      return 0;
   }
else {
       int item = myStack[top--];
      return item;
   }
}
  
//check if stack is empty
bool Stack::isEmpty()
{
   return (top < 0);
}
  
// main program to demonstrate stack functions
int main()
{
   class Stack stack;
   cout<<"The Stack Push "<<endl;
   stack.push(2);
   stack.push(4);
   stack.push(6);
   cout<<"The Stack Pop : "<<endl;
   while(!stack.isEmpty())
      cout<<stack.pop()<<endl;
   return 0;
}
