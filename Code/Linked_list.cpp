#include<iostream>
using namespace std;
template<class T>
class Node
{
  T data;
  Node * next;
public:
	Node()
	{
		next=nullptr;
	}
	Node(T d)
	{
		data=d;
		next=nullptr;
	}
	void setdata(const T element)
	{
		data=element;
	}
	void setnext(Node* n)
	{
		next=n;
	}
	T getdata()
	{
		return data;
	}
	Node * getnext()
	{
		return next;
	}
};
template<class T>
class Linkedlist
{
	Node<int> *  head;
public:
	Linkedlist()
	{
		head=nullptr;
	}
	void insertAtHead(int data)
   {
	   Node<T>* temp=new Node<T>(data);
	   temp->setnext(head);
	   head=temp;
   }
	   void insertAtLast(int data){
	    Node<T>*temp=new Node<T>(data);
		Node<T>*traverse=new Node<T>();
		traverse=head;
		while(traverse->getnext()!=nullptr)
		{
			traverse=traverse->getnext();
		}
		traverse->setnext(temp);
   }
	void swapFL()
	{
		if(head==nullptr)
		{
			return;
		}
		else if(head->getnext()==nullptr)
		{
			return;
		}
		else
		{
			Node<T> * temp=head;
			Node<T> * pre=nullptr;
			while (temp->getnext()!=nullptr)
			{
				pre=temp;
				temp=temp->getnext();
			}
			temp->setnext(head->getnext());
			Node<T> * temp2=head;
			head=temp;
			pre->setnext(temp2);
			temp2->setnext(nullptr);

		}
	}
	void swapGivenNode(int n,int m)
	{
		Node<T> *p1=head;
		Node<T> *p2=head;
		Node<T> *pre1=p1;
		Node<T> *pre2=p2;
		for(int i=1;i<n;i++)
		{
			pre1=p1;
			p1=p1->getnext();
		}
		for(int i=1;i<m;i++)
		{
			pre2=p2;
			p2=p2->getnext();
		}
		Node<T>* move=p2->getnext();
		if(n!=1)
		{
		pre1->setnext(p2);
		}
		else
		{
			p2->setnext(p1->getnext());
			head=p2;
		}
		pre2->setnext(p1);
		if (n!=1)
		{
		 move=p2->getnext();
		}
		if(n!=1)
		{
		 p2->setnext(p1->getnext());
		}
		p1->setnext(move);
	}
	void RotateAnitClockWise(int n)
	{
		Node<T> *check=head;
		int ch=0;
		while (check!=nullptr)
		{
			ch++;
			check=check->getnext();
		}
		if(n!=0 && n<ch)
		{
		Node<T> *p=head;
		Node<T> *pre=p;
		for(int i=0;i<n;i++)
		{
			pre=p;
			p=p->getnext();
		}
		pre->setnext(nullptr);
		pre=p;
		while (pre->getnext()!=nullptr)
		{
			pre=pre->getnext();
		}
		pre->setnext(head);
		head=p;
		}
	}
	void sethead(Node<T> * p)
	{
		head=p;
	}
	void printLinkList()
   {
	   Node<T>* p=head;
		while (p->getnext()!=nullptr)
		{
			cout<<p->getdata()<<" ->";
			p=p->getnext();
		}
		cout<<p->getdata()<<" ->";
		cout<<"NULL\n";
   }
	Node<T> *  sum(Linkedlist a,Linkedlist  b)
	{
		Linkedlist  sum;
		int count1=0;
		int count2=0;
		if(a.head!=nullptr && b.head!=nullptr)
		{
			Node<T> *temp=a.head;
			
		while(temp!=nullptr)
		{
			temp=temp->getnext();
			count1++;
		}
		
		temp=b.head;
		while(temp!=nullptr)
		{
			temp=temp->getnext();
			count2++;
		}
		if(count1<count2)
                {
                  while(count1<count2)
                  {
                    a.insertAtHead(0);
                    count1++;
                  }          

                }
                 else if(count2<count1)
                 {
                  while(count2<count1)
                  {
                    b.insertAtHead(0);
                    count2++;
                  }          

                 }
		if(count1==count2)
		{
			int carry=0;
			while (count1!=0)
			{
				Node<T> *p1=a.head;
				Node<T> *p2=b.head;
				for(int i=1;i<count1;i++)
				{
					p1=p1->getnext();
					p2=p2->getnext();
				}
				int s=p1->getdata()+p2->getdata()+carry;
				carry=s/10;
				s=s%10;
				sum.insertAtHead(s);
				count1--;
			}
			if(carry!=0)
			{
				sum.insertAtHead(carry);
			}
			return sum.head;
		}
		else
		{
			return nullptr;
		}
		}
	}
};
void main()
{
	Linkedlist<int> p;
	p.insertAtHead(2);
	p.insertAtHead(3);
	p.insertAtHead(5);
	p.insertAtHead(10);
	p.insertAtHead(23);
	cout<<"------------------------------------------------------Q1------------------------------------------------------\n"<<endl;
	cout<<"------------------------------------------------------(a)------------------------------------------------------\n"<<endl;
	cout<<"------------------------------------------------Swap First and Last Nodes------------------------------------------------\n"<<endl;
	cout<<"Before: \t";
	p.printLinkList();
	p.swapFL();
	cout<<"After: \t";
	p.printLinkList();
	cout<<"------------------------------------------------------(b)------------------------------------------------------\n"<<endl;
	cout<<"------------------------------------------------Swap Node 2nd and 4th------------------------------------------------\n"<<endl;
	cout<<"Before: \t";
	p.printLinkList();
	p.swapGivenNode(2,4);
	cout<<"After: \t";
	p.printLinkList();
	cout<<"------------------------------------------------------(c)------------------------------------------------------\n"<<endl;
	cout<<"------------------------------------------------Rotate Counter ClockWise from 5th------------------------------------------------\n"<<endl;
	cout<<"Before: \t";
	p.RotateAnitClockWise(5);
	cout<<"After: \t";
	p.printLinkList();
	Linkedlist<int> n,m;
	n.insertAtHead(3);
	n.insertAtHead(2);
	n.insertAtHead(1);
	m.insertAtHead(9);
	m.insertAtHead(9);
	m.insertAtHead(9);
	Linkedlist<int> s;
	cout<<"------------------------------------------------------(d)------------------------------------------------------\n"<<endl;
	s.sethead(s.sum(n,m));
	cout<<"\nList1: \t";
	n.printLinkList();
	cout<<"\nList2: \t";
	m.printLinkList();
	cout<<"\nSum: \t";
	s.printLinkList();
	system("pause");
}