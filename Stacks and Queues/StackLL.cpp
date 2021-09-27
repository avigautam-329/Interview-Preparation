#include<iostream>
using namespace std;


template <typename T>
class Node{
	public:
		T data;
		Node<T>* next;
		Node(T data){
			this->data = data;
			this->next = NULL;
		}
};

template <typename V>
class StackLL{
	int length;
	Node<V>* head;
	
	public:
		StackLL(){
			this->head = NULL;
			this->length = 0;
		}
		
		bool empty(){
			return length == 0;
		}
		
		V top(){
			if(head == NULL){
				cout << "Stack Underflow." << endl;
				return 0;
			}
			
			return this->head->data;
		}
		
		void push(V val){
			Node<V>* newNode = new Node<V>(val);
			if(head == NULL){
				head = newNode;
				this->length++;
				//return head;
			}
			
			newNode->next = this->head;
			this->head = newNode;
			
			this->length++;
			//return head
		}
		
		V pop(){
			if(head == NULL){
				cout << " Stack Underflow." << endl;
				return 0;
			}
			
			V ans = this->head->data;
			head = head ->next;
			this->length--;
			return ans;
		}
		
		int size(){
			return this->length;
		}
};

int main(){
	
	StackLL<int> s1;
	
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	s1.push(60);
	
	cout << s1.top() << endl;
	
	cout << "Popping" << endl;
	cout << s1.pop() << endl;
	cout << s1.pop() << endl;
	
	s1.push(100);
	cout << s1.top() << endl;
	
	return 0;
}
