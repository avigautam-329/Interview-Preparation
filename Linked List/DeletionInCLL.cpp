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

Node* createCLL(){
	int data;
	cin >> data;
	
	Node* head = NULL;
	Node* tail = NULL;
	
	while(data != -1){
		Node* newNode = new Node(data);
		
		if(head == NULL){
			head=  newNode;
			tail = newNode;
		}else{
			tail->next = newNode;
			tail = newNode;
		}
		
		cin >> data;
	}
	
	tail->next = head;
	return head;
}

//Code here.
Node* deletePos(Node* head,int pos){
	if(head == NULL){
		return NULL;
	}
	
	int count = 2;
	Node* prev = head;
	Node* curr = head->next;
	
	if(pos == 1){
		Node* temp = head;
		while(temp->next != head){
			temp = temp->next;
		}
		
		temp->next = head->next;
		head->next = NULL;
		head = temp->next;
		
		return head;
	}
	
	while(count < pos){
		prev = curr;
		curr = curr->next;
		count++;
	}
	
	prev->next = curr->next;
	curr->next = NULL;
	curr = prev->next;
	
	return head;
}

int main(){
	
	Node* head = createCLL();
	
	int pos;
	cout << "Enter the position to be deleted." << endl;
	cin >> pos;
	
	head = deletePos(head , pos);
	
	Node* temp = head;
	while(temp->next != head){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp-> data << " ";
	cout << endl;
	
	return 0;
}
