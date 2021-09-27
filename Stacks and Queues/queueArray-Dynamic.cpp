#include<bits/stdc++.h>
using namespace std;

// If we use dynamic array, then we don't need to recycle the array.

template <typename T>
class queueDynamic{
	T *data;
	int nextElement;
	int firstIndex;
	int capacity;
	int length;
	
	public:
		queueDynamic(){
			this->data = new T[10];
			this->capacity = 10;
			this->nextElement = 0;
			this->firstIndex = -1;
			this->length = 0;
		}
		
		queueDynamic(T size){
			this->data = new T[size];
			this->capacity = size;
			this->nextElement = 0;
			this->firstIndex = -1;
			this->length = 0;
		}
		
		bool empty(){
			return this->length == 0;
		}
		
		int size(){
			return this->length;
		}
		
		T front(){
			if(this->firstIndex == -1){
				cout << " The queue is empty." << endl;
				return 0;
			}
			
			return this->data[this->firstIndex];
		}
		
		T dequeue(){
			if(this->length == 0){
				cout << " The queue is empty." << endl;
				return 0;
			}
			T val = this->data[this->firstIndex];
			this->length--;
			if(this->length == 0){
				this->firstIndex = -1;
				this->nextElement = 0;
			}else{
				this->firstIndex++;
			}
			return val;
		}
		
		void enqueue(T val){
			if(this->length == this->capacity){
				T *newArray = new T[this->capacity * 2];
				for(int i = firstIndex; i < this->capacity; i++){
					newArray[i] = this->data[i];
				}
				delete [] this->data;
				this->data = newArray;
				this->data[this->nextElement] = val;
				this->nextElement++;
				this->length++;
				return;
			}
				this->data[this->nextElement] = val;
				this->nextElement++;
				this->length++;
				if(this->firstIndex == -1){
					this->firstIndex++;
				}
				return;
			
		}
};

int main(){
	queueDynamic<int> q1(5);
	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);
	q1.enqueue(50);
	
	// We should get a error at this point.
	q1.enqueue(60);
	cout << q1.size() << endl;
	cout << q1.front() << endl;
	cout << q1.dequeue() << endl;
	q1.enqueue(60);
	cout << q1.size() << endl;
	cout << q1.front() << endl;
	return 0;
}
