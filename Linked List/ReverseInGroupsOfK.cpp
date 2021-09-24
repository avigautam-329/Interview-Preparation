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

// Funtion to reverse in K.
Node* reverseInK(Node* head , int k){
	// Now we need to reverse the LL in group of K elements.
	Node* prev = NULL;
	Node* fwd;
	Node* curr = head;
	
	// This will keep count of the nodes in the current group.
	int count = 0;
	while(curr != NULL and count < k){
		count++;
		fwd = curr->next;
		curr->next = prev;
		
		prev = curr;
		curr = fwd;
		
		
	}
	
	// Now the other reversed group in front of the current one needs to be connected to the head node's next.
	
	// We check this condition outside the loop because , we need to check before calling the function recursively on the ll and not call it after the ll has ended.
	if(fwd != NULL){
		head->next = reverseInK(fwd , k);	
	}
	
	return prev;
	
}


// Create a linked list.
Node* createLL(){
	Node* head = NULL;
	Node* tail = NULL;
	
	int data;
	cin >> data;
	
	while(data != -1){
		Node *newNode = new Node(data);
		
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		
		tail->next = newNode;
		tail = newNode;
		
		cin >> data;
	}
	return head;
}

int main(){
	Node* head = createLL();
	
	// Now we will take the input for the k.
	int k;
	cin >> k;
	
	cout << "Before reversing in K groups:" << endl;
	Node* temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	
	head = reverseInK(head , k);
	cout << "After reversing in K groups:" << endl;
	temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	
	return 0;
}
