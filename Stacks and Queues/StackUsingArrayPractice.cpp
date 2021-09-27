#include<iostream>
#include<climits>
using namespace std;

template <typename T>
class stackUsingArray{
	T* arr;
	int capacity = 10;
	int nextIdx;
	
	public:
		stackUsingArray(){
			this->arr = new T[this->capacity];
			this->nextIdx = 0;
		}
		
		void push(T data){
			if(nextIdx >= capacity){
				cout << "Stack Overflow." << endl;
				return;
			}
			
			this->arr[this->nextIdx++] = data;
			return;
		}
		
		bool isEmpty(){
			return this->nextIdx == 0;
		}
		
		int size(){
			return this->nextIdx;
		}
		
		int top(){
			if(nextIdx == 0){
				cout << "Stack Empty.";
				return -1;
			}
			
			return this->arr[nextIdx - 1];
		}
		
		int pop(){
			if(nextIdx == 0){
				cout << "Stack Underflow" << endl;
				return INT_MIN;
			}
			
			T ans = this->arr[nextIdx - 1];
			this->nextIdx--;
			
			return ans;
		}
};

int main(){
	
	stackUsingArray<int> s1;
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	s1.push(60);
	s1.push(70);
	s1.push(80);
	s1.push(90);
	s1.push(100);
	s1.push(110);
	
	cout << "Size: " << s1.size() << endl;
	cout << "Top Element : " << s1.top() << endl;
	
	cout << "Popping Element:" << s1.pop() << endl;
	cout << "Size: " << s1.size() << endl;
	cout << "Top Element : " << s1.top() << endl;
	return 0;
}
