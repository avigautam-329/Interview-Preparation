#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		
		Node(int data){
			this->data = data;
			this->next = NULL;
		}
};

// Function to move last element to front.
Node* moveLastToFront(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	
	Node* temp = head;
	Node* prev = NULL;
	
	while(temp->next != NULL){
		prev = temp;
		temp = temp->next;
	}
	
	temp->next = head;
	prev->next = NULL;
	head = temp;
	
	return head;
}



// To take the input.
Node* createLL(){
	int data;
	cin >> data;
	
	Node* head = NULL;
	Node* tail = NULL;
	
	while(data != -1){
		Node* newNode = new Node(data);
		
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		
		tail->next = newNode;
		tail = newNode;
		
		cin >> data;
	}
	
	return head;
}

int main(){
	
	Node* head = createLL();
	
	head = moveLastToFront(head);
	
	Node* temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	return 0;
}
