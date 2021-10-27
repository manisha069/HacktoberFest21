#include <iostream>
using namespace std;

template <typename T>
class Node {
	public:
	T data;
	Node<T> *next;
	
	Node(T val){
		data = val;
		next = NULL;
	}
};

template <typename T>
class QueueUsingLL {
	Node<T> *head;
	Node<T> *tail;
	int size;
	
	public :
	QueueUsingLL(){
		head = NULL;
		tail = NULL;
		size = 0;
	}
	
	int getSize(){
		return size;
	}
	
	bool isEmpty(){
		return size==0;
	}
	
	void enqueue(T val){
		Node<T> *newNode = new Node<T>(val);
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
		size++;
	}
	
	T dequeue(){
		if(isEmpty()){
			cout<<"Queue is empty !"<<endl;
			return 0;
		}
		T ans = head->data;
		Node<T> *temp = head;
		head = head->next;
		delete temp;
		size--;
		return ans;
	}
	
	T front(){
		if(isEmpty()){
			cout<<"Queue is empty !"<<endl;
			return 0;
		}
		return head->data;
	}
};

int main(){
	QueueUsingLL <int> s;
	
	s.enqueue(10);
	s.enqueue(20);
	s.enqueue(30);
	s.enqueue(40);
	s.enqueue(50);
	
	cout<<"Front :"<<s.front()<<endl;
	cout<<"Deleted Top :"<<s.dequeue()<<endl;
	cout<<"Deleted Top :"<<s.dequeue()<<endl;
	cout<<"Deleted Top :"<<s.dequeue()<<endl;
	cout<<"Deleted Top :"<<s.dequeue()<<endl;
	cout<<"Deleted Top :"<<s.dequeue()<<endl;
	cout<<"Deleted Top :"<<s.dequeue()<<endl;
	
	cout<<"Front :"<<s.front()<<endl;
	cout<<"Size :"<<s.getSize()<<endl;
	cout<<"Empty or Not :"<<s.isEmpty()<<endl;
}