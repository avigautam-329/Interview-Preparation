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

Node* detectStartingNode(Node* head){
	if(head == NULL || head->next == NULL){
		return NULL;
	}
	
	Node* slow = head;
	Node* fast = head;
	
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		
		if(slow == fast){
			break;
		}
	}
	
	if(slow == head){
		return head;
	}else if(slow == fast){
		Node* temp = head;
		while(temp->next != fast->next){
			temp = temp->next;
			fast = fast->next;
		}
		
		return fast->next;
	}
	
	return NULL;
}

// To take the input.
Node* createLL(int k){
	int data;
	cin >> data;
	
	Node* head = NULL;
	Node* tail = NULL;
	
	while(data != -1){
		Node* newNode = new Node(data);
		
		if(head == NULL){
			head = newNode;
			tail = newNode;
		}
		
		tail->next = newNode;
		tail = newNode;
		
		cin >> data;
	}
	

	// To create a loop in the linked list.
	if(k != 0){
		int cnt = 1;
		Node *temp = head;
		while(cnt < k){
			cnt++;
			temp = temp->next;
		}
		
		tail->next = temp;	
	}

	return head;
}

int main(){
	

	// Position for looping in Linked list.
	int n;
	cin >> n;
	
	Node* head = createLL(n);
	
	// Function to detect and remove the loop in the linked list.
	Node* loopHead = detectStartingNode(head);
	
	if(loopHead != NULL){
		cout << "The loop starts at node: " << loopHead->data;
	}else{
		cout << "The LL has no loop";
	}
	cout << endl;
	
	return 0;
}
