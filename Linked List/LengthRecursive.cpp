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

int length(Node* head){
	if(head == NULL){
		return 0;
	}
	head = head->next;
	return 1 + length(head);
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
	int count = length(head);
	
	cout << count;
	return 0;
}

