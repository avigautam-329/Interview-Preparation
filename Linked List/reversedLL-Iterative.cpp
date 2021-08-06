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

// Time complexity = O(n).
Node* reverseLL(Node *head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	
	// We shall use the 3 node pointer method.
	Node *prev  = NULL;
	Node *curr = head;
	Node *fwd = head->next;
	
	while(curr != NULL){
		curr->next = prev;
		
		// Now we will move out pointers forward.
		prev = curr;
		curr = fwd;
		
		// If fwd reaches null and we call fwd->next at that point, we will get a segmentation fault error.
		// Soo everytime before moving fwd to fwd->next, we shall check if it has reached NULL or not.
		if(fwd != NULL)
			fwd = fwd->next;
	}
	
	// We are return prev because prev will now become the head of the reversed Linked List.
	return prev;
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
