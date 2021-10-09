#include<iostream>
#define max 20
using namespace std;
class stack
{
	int top;
	int a[max];
	public:
		void init()
		{
			top=-1;
		}
		void push(int n);
		int pop();
		int peek();
		void display();
};
void stack::push(int n)
{
	if(top==max-1)
	{
		cout<<"overflow";
		return ;
	}
	top++;
	a[top]=n;
}
int stack::pop()
{
	int n;
	if(top==-1)
	{
		cout<<"underflow";
		return -9;
	}
	n=a[top];
	top--;
	return n;
}
int stack::peek()
{
	int n;
	if(top==-1)
	{
		cout<<"underflow";
		return -9;
	}
	n=a[top];
	return n;
}
void stack::display()
{
	int i;
	for(i=top;i>=0;i--)
	{
		cout<<"\n"<<a[i];
	}
}
int main()
{
	int ch,n;
	stack s;
	s.init();
    cout<<"\nmenu";
	cout<<"\n1.push\n2.pop\n3.peek\n4.display";
	do
	{
		cout<<"\nenter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"\nenter the no to push:";
					cin>>n;
					s.push(n);
					break;
			case 2: n=s.pop();
					if(n!=-9)
						cout<<"popped element="<<n;
					break;	
			case 3: n=s.peek();
					if(n!=-9)
						cout<<"peek element="<<n;	
				    break;
			case 4: s.display();
					break;
			default: cout<<"invalid";		
		}
	}
	while(1);
}
