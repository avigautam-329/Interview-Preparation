#include<iostream>
#include<queue>

using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		
		Node(int data){
			this->data = data;
			this->next = NULL;
			this->prev = NULL; 
		}
};


Node* createDLL(){
	int data;
	cin >> data;
	
	Node* head = NULL;
	Node* tail = NULL;
	
	while(data != -1){
		Node* newNode = new Node(data);
		
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
		}
		
		cin >> data;
	}
	
	return head;
}

// Code here.
Node* sortedK(Node* head , int k){
	if(head == NULL || head->next == NULL || k == 1){
		return head;
	}
	
	// First we will create a min heap.
	priority_queue<int , vector<int> , greater<int>> kElements;
	
	
	// Second: We wil fill the min heap with the first k elements.
	Node* temp = head;
	int count = 0;
	while(temp != NULL && count < k){
		kElements.push(temp->data);
		temp = temp->next;
	}
	
	
	// Third: Now we will start putting the elements to its correct places.
	Node* pos = head;
	while(temp != NULL){
		int minElem = kElements.top();
		kElements.pop();
		
		pos->data = minElem;
		pos = pos->next;
		
		temp = temp->next;
	}
	
	// Filling the DLL with the left over elements of min heap.
	while(!kElements.empty()){
		pos->data = kElements.top();
		kElements.pop();
		
		pos = pos->next;
	}
	
	return head;
	
}

int main(){
	Node* head = createDLL();
	
	int k;
	cin >> k;
	
	cout << "Before Sorting:" << endl;
	Node* temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	

	head = sortedK(head , k);
	
	temp = head;
	cout << "After sorting:" << endl;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	
	return 0;
}
