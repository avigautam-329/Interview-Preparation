#include<bits/stdc++.h>
#include<climits>
using namespace std;

template <typename T>
class StackUsingArray{
	T *data;
	int nextElement;
	int capacity;
	
	public:
		StackUsingArray(){
			this->capacity = 10;
			this->data = new T[this->capacity];
			this->nextElement = 0;
		}
		
		StackUsingArray(int size){
			this->capacity = size;
			this->data = new T[this->capacity];
			this->nextElement = 0;
		}
		
		// Return the size of the stack.
		T size(){
			return this->nextElement;
		}
		
		// Return the top element.
		T top(){
			if(this->nextElement == 0){
				cout << "Stack Underflow." << endl;
				return INT_MIN;
			}else{
				return this->data[this->nextElement-1];
			}
		}
		
		bool isEmpty(){
			return this->nextElement == 0;
		}
		
		T pop(){
			if(this->nextElement == 0){
				cout << "Stack Underflow." << endl;
				return INT_MIN;
			}else{
				int ans = this->data[this->nextElement-1];
				this->nextElement--;
				return ans;
			}
		}
		
		void push(int element){
			if(this->nextElement >= this->capacity){
				cout << "Stack OverFlow." << endl;
				
			}else{
				this->data[this->nextElement] = element;
				this->nextElement++;
			}
		}
};


int main(){
	int capacity;
	cin >> capacity;
	
	StackUsingArray<int> s1(capacity);
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	s1.push(60);
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	cout << s1.top() << endl;
	s1.push(70);
	cout << s1.top() << endl;
	
	
	return 0;
}
