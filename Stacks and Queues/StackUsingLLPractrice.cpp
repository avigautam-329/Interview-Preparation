#include<iostream>
#include<climits>
using namespace std;

// I have also nested the template calls, in stackUsingLL class.

// First create the node class.
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
class stackUsingLL{
	Node<V>* head;
	int capacity;
	
	public:
		stackUsingLL(){
			this->head = NULL;
			this->capacity = 0;
		}
		
		bool isEmpty(){
			return this->head == NULL;
		}
		
		int size(){
			return this->capacity;
		}
		
		void push(V data){
			Node<V>* newNode = new Node<V>(data);
			if(this->head == NULL){
				head = newNode;
				this->capacity++;
			}else{
				newNode->next = head;
				head = newNode;
				this->capacity++;
			}
			
			return;
		}
		
		V top(){
			if(head == NULL){
				cout << "Stack is empty." << endl;
				return 0;
			}
			
			return head->data;
		}
		
		V pop(){
			if(head == NULL){
				cout << "Stack Underflow." << endl;
				return 0;
			}
			
			V ans = head->data;
			head = head->next;
			this->capacity--;
			return ans;
		}
};

int main(){
	
	stackUsingLL<int> s1;
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
