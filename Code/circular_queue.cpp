#include<iostream>

#define MAX 5

using namespace std;

class Queue{
	private:
		int front, rear;
		int arr[MAX];
	public:	
		Queue(){
			front = -1;
			rear = -1;
			for(int i = 0; i< MAX; i++){
				arr[i] = 0;
			}
		}
		bool isEmpty(){
			if (front == -1 && rear == -1)
				return true;
			else
				return false;
		}
		bool isFull(){
			if((rear+1)%MAX == front)
				return true;
			else
				return false;
		}
		void enQueue(int val){
			if (isFull()){
				cout << "Queue is full" << endl;
				return;
			}
			else if(isEmpty()){
				rear = front = 0;
			}
			else{
				rear = (rear+1) % MAX;
			}
			arr[rear] = val;
		}
		void deQueue(){
			if (isEmpty()){
				cout << "Queue is Empty" << endl;
				return;
			}
			else if(front == rear){
				int temp = arr[front];
				front = rear = -1;
				cout<< temp << " is deleted" << endl;
			}
			else{
				int x = arr[front];
				front = (front+1)%MAX;	
				cout << x << " is deleted" << endl;
			}
		}
		void firstEle(){
			if (isEmpty())
				cout << "Queue is empty" << endl;
			else
				cout << arr[front]<<" is the front value" << endl;
		}
		void display(){
			if(isEmpty())
				cout << "Queue is empty" << endl;
			else if(rear>=front){
				for(int i = front; i <= rear; i++)
					cout << arr[i] << " ";
				cout<<endl;
			}
			else{
				for(int i = front; i < MAX; i++)
					cout << arr[i] << " ";
				for(int i = 0; i <= rear; i++)
					cout << arr[i]<< " ";
				cout << endl;
			}
		}
};


int main(){
	Queue q;
	int val, ch;
	while(1){
		cout << "1. Enqueue \n2. Dequeue\n3. front\n4. exit\nEnter your choice: ";	
		cin >> ch;
		switch(ch){
			case 1:
				cout << "Enter a value to enqueue: ";
				cin >> val;
				q.enQueue(val);
				q.display();
				break;
			case 2:
				q.deQueue();
				q.display();
				break;
			case 3:
				q.firstEle();
				break;
			case 4:
				exit(0);
			default:
				cout << "\nPlease enter a correct choice\n";
		}
	}
	return 0;	
}
