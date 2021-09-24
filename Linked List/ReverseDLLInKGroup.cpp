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

Node* reverseK(Node* head , int k){
	if(head == NULL || head->next == NULL){
		return head;
	}
	
	Node* prev = NULL;
	Node* curr = head;
	Node* fwd = head->next;
	int cnt = 0;
	
	while(curr != NULL && cnt < k){
		curr->next = prev;
		curr->prev = fwd;
		prev = curr;
		curr = fwd;
		
		fwd = fwd->next;
		
	}
	if(fwd != NULL){
		head->next = 
	}
	
}

int main(){
	
	return 0;
}
