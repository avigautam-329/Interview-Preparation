#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
		
		Node(int data){
			this->data = data;
			this->next = NULL;
			this->prev = NULL;
		}
};

// Code here.
void getPair2Sum(Node* head , int sum){
	if(head == NULL || head->next == NULL){
		return;
	}
	
	// First step is to create 2 pointers and make one pointer point to the start and the other to the end.
	Node* first = head;
	Node* second = head;
	
	while(second->next != NULL){
		second = second->next;
	}
	
	// Now we will run the loop till the 2 pointers don't intersect each other.
	while(first != second){
		int currSum = first->data + second->data;
		
		if(currSum == sum){
			// If we move only one of the pointers forward/backward , the sum will either increase from sum or decrease.
			// Soo first we will print this pair.
			cout << '(' << first->data << " , " << second->data << ')' << endl;
			
			first = first->next;
			second = second->prev; 
		}else{
			// If the currSum is not equal to sum, then it might be less or greater.
			if(currSum > sum){
				second = second->prev;
			}else{
				first = first->next;
			}
		}
	}
	
	return;
}



// Creating a doubly linked list.
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
			newNode->prev = tail;
			tail = newNode;
			
		}
		
		cin >> data;
	}
	return head;
}



int main(){
	Node* head = createLL();
	
	int sum;
	cin >> sum;
	
	getPair2Sum(head , sum);
	
	return 0;
}
