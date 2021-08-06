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


// Time complexity : O(n).
pair<Node*, Node*> reverseLL(Node *head){
	if(head == NULL){
		pair<Node*, Node*> ans;
		ans.first = NULL;
		ans.second = NULL;
		return ans;
	}
	
	if(head ->next == NULL){
		pair<Node*, Node*> ans;
		ans.first = head;
		ans.second = head;
		return ans;
	}
	
	pair<Node*, Node*> smallAns = reverseLL(head->next);
	
	// Now as we both the head oand the tail of the already reversed LL.
	// We can now assign the current head to the tail of this reversed LL.
	pair<Node* , Node*> finalAns;
	finalAns.first = smallAns.first;
	
	smallAns.second->next = head;
	head->next = NULL;
	smallAns.second = head;
	
	finalAns.second = smallAns.second; 
	return finalAns;
}

Node *takeInput(){
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
	
	head = reverseLL(head).first;
	Node *temp = head;
	while(temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	return 0;
}
