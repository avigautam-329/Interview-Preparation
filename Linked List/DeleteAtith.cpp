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

Node* deleteAtith(Node *head, int i){
	if(head == NULL){
		return NULL;
	}
	
	if(i == 0){
		head = head->next;
		return head;
	}
	
	int pos = 0;
	Node* temp = head;
	while(temp->next != NULL && pos < i-1){
		temp = temp->next;
		pos++;
	}
	
	if(temp->next != NULL){
		
		Node *newNode = temp->next; 
		temp->next = temp->next->next;
		newNode->next = NULL;
		
	}
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
	
	int i;
	cin >> i; 
	
	head = deleteAtith(head, i);
	Node *temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	return 0;
}
