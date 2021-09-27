#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node{
	public:
		T data;
		Node<T>* next;
		Node(T val){
			this->data = val;
			this->next = NULL;
		}
};


template <typename V>
class QueueLL{
	Node<V>* front;
	Node<V>* rear;
	int length;
	public:
		QueueLL(){
			this->front = NULL;
			this->rear = NULL;
			this->length = 0;
		}
	
		
		// Insertions are going to be at the rear. According to the definition.
		bool empty(){
			return this->empty() == 0;
		}
		
		int size(){
			return this->length;
		}
		
		V frontLL(){
			if(this->length == 0){
				cout << " The queue is empty" << endl;
				return 0;
			}
			
			return this->front->data;
		}
		
		V dequeue(){
			if(this->length == 0){
				cout << " The queue is empty" << endl;
				return 0;
			}
			
			V val = this->front->data;
			this->front = this->front->next;
			this->length--;
			return val;
		}
		
		void enqueue(V val){
			Node<V> *newNode = new Node<V>(val);
			if(this->front == NULL){
				this->front = newNode;
				this->rear = newNode;
				this->length++;
			}
			
			this->rear->next = newNode;
			this->rear = newNode;
			this->length++;
		}
};

int main(){
	QueueLL<int> q1;
	
	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);
	q1.enqueue(50);
	
	cout << "the current size is : " << q1.size() << endl;
	
	cout << "The current front : " << q1.frontLL() << endl;
	
	cout << "Dequeue : " << q1.dequeue() << endl;
	cout << "Dequeue : " << q1.dequeue() << endl;
	cout << "Dequeue : " << q1.dequeue() << endl;
	
	cout << "the current size is : " << q1.size() << endl;
	
	cout << "The current front : " << q1.frontLL() << endl;
	 
	return 0;
}
