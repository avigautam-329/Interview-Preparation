#include<iostream>
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

/*
	The algorithm:
		- We will first make the DLL a circular DLL.
		- Next we will move the head by k positions.
		- Lastly we will break the circular DLL to get a normal DLL again.

*/
Node* rotateN(Node* head, int k){
	if(head == NULL || head->next == NULL){
		return head;
	}
	
	Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = head;
	head->prev = temp;
	
	int cnt = 0;
	Node* prev = temp;
	while(cnt < k){
		cnt++;
		prev = head;
		head = head->next;
	}
	
	head->prev = NULL;
	prev->next = NULL;
	
	return head;
	
}


int main(){
	Node* head = createDLL();
	
	int k;
	cin >> k;
	
	
	
	Node* temp = head;
	cout << "Before Rotating: " << endl;
	while(temp != NULL){
		cout << temp->data << " ";
		temp =temp->next;
	}
	cout << endl;	
	
	head = rotateN(head , k);
	temp = head;
	cout << "After Rotating: " << endl;
	while(temp != NULL){
		cout << temp->data << " ";
		temp =temp->next;
	}
	cout << endl;
	
	return 0;
}

