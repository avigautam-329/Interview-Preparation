#include<bits/stdc++.h>
using namespace std;

// This is our node class.
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
	// Now we have to write a function to take the input.
	// Soo that function will return the head of our desired LL.
	Node *head = takeInput();
	
	Node *temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	return 0;
}
