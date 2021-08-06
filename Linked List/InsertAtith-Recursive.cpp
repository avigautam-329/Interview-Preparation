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

Node* insertRecur(Node* head, int pos , int newData){
	
	// The position index is out of bounds.
	if(pos == 0){
		Node *newNode = new Node(newData);
		newNode->next = head;
		head = newNode;
		return head;
	}
	if(head == NULL){
		return NULL;
	}
	
	Node *temp = insertRecur(head->next, pos- 1, newData);
	head->next = temp;
	return head;
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
		}
		else{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}



int main(){
	Node *head = takeInput();
	int i, newData;
	cin >> i;
	cin >> newData;	
	
	head = insertRecur(head, i , newData);
	
	Node *temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	return 0;
}
