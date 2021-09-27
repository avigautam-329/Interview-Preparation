#include<iostream>
#include<climits>
using namespace std;


template <typename T>
class StackDynamic{
	T *data;
	int nextElement;
	int capacity;
	
	public:
		StackDynamic(){
			this->data = new T[10];
			this->nextElement = 0;
			this->capacity = 10;
		}
		
		StackDynamic(int size){
			this->data = new T[size];
			this->nextElement = 0;
			this->capacity = size;
		}
		
		bool empty(){
			return nextElement == 0;
		}
		
		int size(){
			return  this->nextElement;
		}
		
		T top(){
			if(this->nextElement == 0){
				cout << "Stack underflow." << endl;
				return INT_MIN;
			}
			return this->data[this->nextElement - 1];
		}
		
		T pop(){
			if(this->nextElement == 0){
				cout << " Stack Underflow." << endl;
				return INT_MIN;
			}
			T val = this->data[this->nextElement - 1];
			this->nextElement--;
			return val;
		}
		
		void push(T val){
			if(this->nextElement == this->capacity && this->capacity != INT_MAX){
				// We will have to increase the size of the stack.
				T *newArray = new T[this->capacity * 2];
				for(int i = 0; i < this->capacity; i++){
					newArray[i] = this->data[i];
				}
				delete [] this->data;
				// Now after deleteing the data array, data becomes a dangling pointer.
				// Soo we will reassign the pointer.
				this->data = newArray;
				
				this->data[this->nextElement++] = val;
				this->capacity *= 2;
			}else{
				this->data[this->nextElement++] = val;
			}
		}
};


int main(){
	int size;
	cin >> size;
	
	StackDynamic<int> s1(4);
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	
	//When I enter this element, then we shouldn't get any error. 
	s1.push(50);
	
	cout << s1.top() << endl;
	return 0;
}
