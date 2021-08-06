#include<bits/stdc++.h>
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

// TIME COMPLEXITY IS : O(N).
Node* reverseLL(Node *head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	
	Node *smallAns = reverseLL(head->next);
	
	Node* tail = head->next;
	tail->next = head;
	tail = head;
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
