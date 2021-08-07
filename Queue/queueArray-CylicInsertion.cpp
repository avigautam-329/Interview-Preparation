#include<iostream>
using namespace std;

template <typename T>
class queueArray{
	T *data;
	int nextElement;
	
	// This will tell us what element is kept at the front of the queue.
	int firstIndex;
	
	int length;
	
	int capacity;
	
	public:
		queueArray(){
			this->data = new T[10];
			this->nextElement = 0;
			
			// This is -1 because at the moment the queue is empty.
			this->firstIndex = -1;
			
			this->length = 0;
			this->capacity = 10;
		}
		
		queueArray(int capacity){
			this->data = new T[capacity];
			this->nextElement = 0;
			this->firstIndex = -1;
			this->length = 0;
			this->capacity = capacity;
		}
		
		bool empty(){
			return this->size == 0;
		}
		
		int size(){
			return this->length;
		}
		
		T front(){
			if(this->firstIndex == -1){
				cout << "Empty queue." << endl;
				return 0;
			}
			
			return this->data[this->firstIndex];
		}
		
		T dequeue(){
			if(this->length == 0){
				cout << "Queue empty." << endl;
				return 0;
			}
			
			T val = this->data[this->firstIndex];
			this->length--;
			
			// If after removing the element the queue becomes empty, then we need to reset the firstIndex.
			if(this->length == 0){
				this->firstIndex = -1;
			}else{
				this->firstIndex = (this->firstIndex + 1) % this->capacity;
			}
			return val;
		}
		
		void enqueue(T val){
			if(this->length == this->capacity){
				cout << "The queue is full." << endl;
				return;
			}
			this->data[this->nextElement] = val;
			this->nextElement = (this->nextElement + 1) % this->capacity;
			if(this->firstIndex == -1){
				this->firstIndex++;
			}
			this->length++;
		}
	
};

int main(){
	
	queueArray<int> q1(5);
	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);
	q1.enqueue(50);
	
	// We should get a error at this point.
	q1.enqueue(60);
	
	cout << q1.front() << endl;
	cout << q1.dequeue() << endl;
	q1.enqueue(60);
	cout << q1.front() << endl;
	return 0;
}
