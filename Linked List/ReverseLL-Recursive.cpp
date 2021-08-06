#include<iostream>
using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node(int data){
			this->data = data;
			this->next = NULL;
		}
};

// Time complexity = O(nlog(n)).
Node* reverseLL(Node *head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	
	// Now when we call the recursive function we will assume that the list that we get is already reversed, soo the last element will be at the front
	// and we need to store the address of that head in a new pointer.
	// After storing , we need to take out current element at hand and put it at the end.
	// And make that element point to NULL.
	Node *smallAns = reverseLL(head->next);
	
	// The current element at hand is stored in head pointer.
	// To insert the elemnt at the end, we need to travel till the end as well.
	Node *temp = smallAns;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = head;
	head->next = NULL;
	return smallAns;
}

Node* takeInput(){
	int data;
	cin >> data;
	
	Node *head = NULL;
	Node *tail = NULL;
	
	while(data != -1){
		Node *newNode = new Node(data);
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}


int main(){
	
	Node *head = takeInput();
	
	head = reverseLL(head);
	
	Node *temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
