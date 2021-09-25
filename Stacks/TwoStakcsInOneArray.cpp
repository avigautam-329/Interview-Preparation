#include<iostream>
#include<climits>
#include<vector>
using namespace std;


template <typename T>
class TwoStacksInOneArray{
	T* arr;
	int capacity;
	int nextElement1 , nextElement2;
	
	public:
		TwoStacksInOneArray(int capacity){
			this->capacity = capacity;
			this->arr = new T[this->capacity];
			this->nextElement1 = 0;
			this->nextElement2 = capacity - 1;
		}
		
		// Operations for first Stack.
		// The first Stack will start from 0 index.
		bool isEmpty1(){
			return this->nextElement1 == 0;
		}
		
		int size1(){
			return this->nextElement1;
		}
		
		void push1(T data){
			if(this->nextElement1 > this->nextElement2){
				cout << "Stack 1 Overflow." << endl;
				return;
			}
			
			this->arr[this->nextElement1++] = data;
			return;
		}
		
		T pop1(){
			if(this->nextElement1 == 0){
				cout << "Stack1 underflow." << endl;
				return INT_MIN;
			}
			
			T ans = this->arr[this->nextElement1 - 1];
			
			this->nextElement1--;
			return ans;
		}
		
		T top1(){
			if(this->nextElement1 == 0){
				cout << "Stack1 is empty." << endl;
				return INT_MIN;
			}
			
			return this->arr[this->nextElement1 - 1];
		}
		
		// This is the start of the second stack.
		// stack 2 will start from the right end of the array.
		bool isEmpty2(){
			return this->nextElement2 == this->capacity - 1;
		}
		
		int size2(){
			return (this->capacity - this->nextElement2);
		}
		
		void push2(T data){
			if(this->nextElement2 < this->nextElement1){
				cout << "Stack 2 Overflow." << endl;
				return;
			}
			
			this->arr[this->nextElement2--] = data;
			return;
		}
		
		T pop2(){
			if(this->nextElement2 == this->capacity - 1){
				cout << "Stack2 underflow." << endl;
				return INT_MIN;
			}
			
			T ans = this->arr[this->nextElement2 + 1];
			
			this->nextElement2++;
			return ans;
		}
		
		T top2(){
			if(this->nextElement2 == this->capacity - 1){
				cout << "Stack2 is empty." << endl;
				return INT_MIN;
			}
			
			return this->arr[this->nextElement2 + 1];
		}
};

int main(){
    vector<int> arr1 = { 1, 2, 3, 4, 5 };
    vector<int> arr2 = { 6, 7, 8, 9, 10 };
 
    TwoStacksInOneArray<int> s(arr1.size() + arr2.size());
 
    for (int i: arr1) {
        s.push1(i);
    }
 
    for (int j: arr2) {
        s.push2(j);
    }
 
    cout << "Popping element from the first stack: "
         << s.pop1() << endl;
 
    cout << "Popping element from the second stack: "
         << s.pop2() << endl;
 
    return 0;
	
	return 0;
}
