/*
How to implement a stack which will support following operations in O(1) time complexity? 
1) push() which adds an element to the top of stack. 
2) pop() which removes an element from top of stack. 
3) findMiddle() which will return middle element of the stack. 
4) deleteMiddle() which will delete the middle element. 
Push and pop are standard stack operations. 
*/


#include<iostream>
using namespace std;

template <typename T>
class Node{
	public:
		int data;
		Node<T>* next;
		Node<T>* prev;
		
		public:
			Node(T data){
				this->data = data;
				this->next = NULL;
				this->prev = NULL;
			}
};


template <typename V>
class StackWithMiddle{
	Node<V>* head;
	Node<V>* middle;
	int capacity;
	
	public:
		StackWithMiddle(){
			this->head = NULL;
			this->middle = NULL;
			this->capacity = NULL;
		}
		
		// Operations.
		bool isEmpty(){
			return this->capacity == 0;
		}
		
		int size(){
			return this->capacity;
		}
		
		V getMiddle(){
			if(this->middle == NULL){
				cout << "Middle Element is Empty." << endl;
				return 0;
			}
			
			return this->middle->data;	
		}
		
		void push(V data){
			// Insert the element.
			// Change the middle based on even and odd size.
			Node<V>* newNode = new Node<V>(data);
			this->capacity++;
			if(head == NULL){
				head = newNode;
				middle = newNode;
			}
			else{
				head->prev = newNode;
				newNode->next = head;
				head = newNode;
				
				// We also need to move the middle pointer.
				if(capacity % 2 != 0){
					middle = middle->prev;
				}
			}
			
			return;
					
		}
		
		V pop(){
			if(head == NULL){
				cout << "Stack UnderFlow." << endl;
				return 0;
			}
			
			this->capacity--;
			
			V ans = this->head->data;
			Node<V>* temp = head;
			head = head->next;
			head->prev = NULL;
			temp->next = NULL;
			delete temp;
			
			if(this->capacity % 2 == 0 && capacity != 0){
				middle = middle->next;
			}
			
			return ans;
		}
		
		V top(){
			if(head == NULL){
				cout << "Stack is Empty." << endl;
				return 0;
			}
			
			return this->head->data;
		}
		
		// delete middle.
		V deleteMiddle(){
			if(middle == NULL){
				cout << "Stack is Empty." << endl;
				return 0;
			}
			
			V ans = middle->data;
			if(middle == head){
				
				delete middle;
				middle = NULL;
				head = NULL;
			}
			
			Node<V>* temp = middle->prev;
			temp->next = middle->next;
			if(middle->next != NULL){
				middle->next->prev = temp;
			}else{
				middle->prev = NULL;
			}
			middle = temp->next;
			
			return ans;
		}
	
};

int main(){
	StackWithMiddle<int> s1;
	
	s1.push(10);
	s1.push(20);
	
	cout << "The current middle is: " << s1.getMiddle() << endl;
	
	s1.push(30);
	s1.push(40);
	s1.push(50);
	cout << "The current middle is: " << s1.getMiddle() << endl;
	
	cout << "Deleting the middle element: " << s1.deleteMiddle() << endl;
	cout << "The current middle is: " << s1.getMiddle() << endl;
	
	return 0;
}
