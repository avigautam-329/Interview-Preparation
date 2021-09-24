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

Node* createLL(){
	int data;
	cin >> data;
	
	Node* head = NULL;
	Node* tail = NULL;
	
	while(data != -1){
		Node* newNode = new Node(data);
		
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

// Code here.

Node* merge(Node* head1 , Node* head2){
	if(head1 == NULL){
		return head2;
	}
	
	if(head2 == NULL){
		return head1;
	}
	
	
	Node* finalHead = NULL;
	Node* finalTail = NULL;
	
	Node* temp1 = head1;
	Node* temp2 = head2;
	
	while(temp1 != NULL && temp2 != NULL){
		if(temp1->data < temp2->data){
			if(finalHead == NULL){
				finalHead = temp1;
				finalTail = temp1;
			}else{
				finalTail->next = temp1;
				finalTail = temp1;
			}
			
			temp1 = temp1->next;
		}else{
			if(finalHead == NULL){
				finalHead = temp2;
				finalTail = temp2;
			}else{
				finalTail->next = temp2;
				finalTail = temp2;
			}
			temp2 = temp2->next;
		}
	}
	
	while(temp1 != NULL){
		finalTail->next = temp1;
		finalTail = temp1;
		
		temp1 = temp1->next;
	}
	
	while(temp2 != NULL){
		finalTail->next = temp2;
		finalTail = temp2;
		
		temp2 = temp2->next;
	}
	
	return finalHead;
}

Node* mergeSort(Node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	
	// First find the middle point to spilt the linked list.
	Node* slow = head;
	Node* fast = head->next;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	
	// Now using the slow pointer we will spilt the linked list into 2 parts.
	Node* head2 = slow->next;
	
	Node* head1 = head;
	slow->next = NULL;
	
	head1 = mergeSort(head1);
	head2 = mergeSort(head2);
	
	Node* finalHead = merge(head1 , head2);
	
	return finalHead;
}

int main(){
	Node* head = createLL();
	
	Node* temp = head;	
	cout << "Before Sorting : " << endl;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	
	head = mergeSort(head);
	temp = head;
	cout << "After Sorting : " << endl;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	return 0;
}
