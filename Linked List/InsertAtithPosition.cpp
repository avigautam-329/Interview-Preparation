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


Node* takeInput(){
	Node* head = NULL;
	Node* tail = NULL;
	int data;
	cin >> data;
	
	
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

Node* insertAtIth(Node *head, int i, int data){
	
	Node *newNode = new Node(data);
	if(head == NULL){
		head = newNode;
		return head;
	}
	if(i == 0){
		newNode->next = head;
		head = newNode;
		return head;
	}
	
	int pos = 0;
	Node *curr = head;
	//Node *prev = head;
	
	while(curr->next != NULL && pos < i-1){
		curr = curr->next;
		pos++;
	}
	
	if(curr->next == NULL){
		curr->next = newNode;
	}else{
		newNode->next = curr->next;
		curr->next = newNode;
	}
	
	return head;

}

int main(){
	Node *head = takeInput();
	
	int i , newData;
	cin >> i;
	cin >> newData;
	
	head = insertAtIth(head, i , newData);
	
	Node *temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
